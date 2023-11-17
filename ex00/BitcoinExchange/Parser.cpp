/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParserEnv.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:55:41 by htsang            #+#    #+#             */
/*   Updated: 2023/11/12 00:29:45 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

#include <cerrno>
#include <cstdlib>
#include <cstddef>

#include <string>
#include <utility>
#include <limits>

#include "Result.hpp"
#include "Date.hpp"
#include "BitcoinExchange.hpp"

namespace bitcoin_exchange
{
  ///////////////////////////////////////////////////
  ////////////   ParserEnv environment   ////////////
  ///////////////////////////////////////////////////

  ParserEnv::ParserEnv(std::string::iterator it, std::string::iterator end)
    : it(it), end(end) {}

  ParserEnv::ParserEnv(ParserEnv const& other)
    : it(other.it), end(other.end) {}

  ParserEnv& ParserEnv::operator=(ParserEnv const& other)
  {
    if (this != &other)
    {
      it = other.it;
      end = other.end;
    }
    return *this;
  }

  ////////////////////////////////////////////////////////
  ////////////   ParserSettings environment   ////////////
  ////////////////////////////////////////////////////////

  ParserSettings::ParserSettings(std::string delimiter, BitcoinExchange::Headers headers, float max_rate)
    : delimiter(delimiter), headers(headers), max_rate(max_rate) {}

  ///////////////////////////////////////////////////////////////////////
  ////////////   ParserEnv action (Use by bitcoinExchange)   ////////////
  ///////////////////////////////////////////////////////////////////////

  HeadersParseResult  ParseHeaders(std::pair<ParserEnv*, ParserSettings> env_with_delimiter)
  {
    BitcoinExchange::Headers headers;
    ParserEnv                env = *env_with_delimiter.first;

    return ParseUntilDelimiter(std::make_pair(&env, env_with_delimiter.second.delimiter))
      .chain(&TrimString, env)
      // .chain(&ValidateHeader, env_with_delimiter.second.headers.date)
      .chain(&SavesValueTo<std::string>, &headers.date)
      .chain(&ParseWhitespaces, env)
      .chain(&ParseDelimiter, std::make_pair(&env, env_with_delimiter.second.delimiter))
      .chain(&ParseWhitespaces, env)
      .chain(&ParseUntilEof, env)
      .chain(&TrimString, env)
      // .chain(&ValidateHeader, env_with_delimiter.second.headers.rate)
      .chain(&SavesValueTo<std::string>, &headers.rate)
      .chain(&ParseEnd, env)
      .chain(&UpdateEnv, std::make_pair(env_with_delimiter.first, env))
      .chain(&Return<BitcoinExchange::Headers>, headers);
  }

  EntryParseResult    ParseEntry(std::pair<ParserEnv*, ParserSettings> env_with_delimiter)
  {
    Entry       entry;
    ParserEnv   env = *env_with_delimiter.first;

    return ParseDate(env)
      .chain(&SavesValueTo<Date>, &entry.first)
      .chain(&ParseWhitespaces, env)
      .chain(&ParseDelimiter, std::make_pair(&env, env_with_delimiter.second.delimiter))
      .chain(&ParseWhitespaces, env)
      .chain(&ParseRate, std::make_pair(&env, env_with_delimiter.second.max_rate))
      .chain(&SavesValueTo<float>, &entry.second)
      .chain(&ParseEnd, env)
      .chain(&UpdateEnv, std::make_pair(env_with_delimiter.first, env))
      .chain(&Return<Entry>, entry);
  }

  ///////////////////////////////////////////////////////////////
  ////////////   ParserEnv action (implementation)   ////////////
  ///////////////////////////////////////////////////////////////

  DateParseResult   ParseDate(ParserEnv& env)
  {
    Date      date;
    ParserEnv new_env = env;

    return ParseInt(new_env)
      .chain(&SavesValueTo<int>, &date.year)
      .chain(&ParseDelimiter, std::make_pair(&new_env, std::string("-")))
      .chain(&ParseInt, new_env)
      .chain(&SavesValueTo<int>, &date.month)
      .chain(&ParseDelimiter, std::make_pair(&new_env, std::string("-")))
      .chain(&ParseInt, new_env)
      .chain(&SavesValueTo<int>, &date.day)
      .chain(&UpdateEnv, std::make_pair(&env, new_env))
      .chain(&Return<Date>, date);
  }

  RateParseResult   ParseRate(std::pair<ParserEnv*, float> env_with_maximum_rate)
  {
    ParserEnv* env = env_with_maximum_rate.first;
    char* endptr;
    errno = 0;
    double rate = std::strtod(&*env->it, &endptr);
    if (errno == ERANGE || (0 > rate) || (rate > env_with_maximum_rate.second))
      return RateParseResult::Error(BitcoinExchange::kOutOfRangeRate);
    else if (rate < 0)
      return RateParseResult::Error(BitcoinExchange::kNegativeRate);
    else
    {
      env->it += (endptr - &*env->it);
      return RateParseResult::Ok(static_cast<float>(rate));
    }
  }

  IntParseResult  ParseInt(ParserEnv& env)
  {
    char* endptr;
    errno = 0;
    int value = std::strtol(&(*env.it), &endptr, 10);
    if (errno == ERANGE || 
      ((static_cast<long>(std::numeric_limits<int>::max()) < value) &&
      (value < static_cast<long>(-std::numeric_limits<int>::max()))))
      return IntParseResult::Error(BitcoinExchange::kOutOfRangeRate);
    else
    {
      env.it += (endptr - &*env.it);
      return IntParseResult::Ok(value);
    }
  }

  StringParseResult   ParseUntilDelimiter(std::pair<ParserEnv*, std::string> env_with_delimiter)
  {
    ParserEnv         env = *env_with_delimiter.first;
    const std::string delimiter = env_with_delimiter.second;

    // parse without saving the delimiter
    while (std::distance(env.it, env.end) >= static_cast<ptrdiff_t>(delimiter.size()) &&
      !std::equal(env.it, env.it + delimiter.size(), delimiter.begin()))
      ++env.it;
    std::string result(env_with_delimiter.first->it, env.it);
    *env_with_delimiter.first = env;
    return StringParseResult::Ok(result);
  }

  StringParseResult   TrimString(std::string string, ParserEnv& env)
  {
    (void) env;
    std::string::iterator it = string.begin();
    while (std::isspace(*it))
      ++it;
    string.erase(string.begin(), it);
    it = string.end();
    while (std::isspace(*(it - 1)))
      --it;
    string.erase(it, string.end());
    return StringParseResult::Ok(string);
  }

  StringParseResult   ParseUntilEof(ParserEnv& env)
  {
    std::string::iterator it = env.it;
    env.it = env.end;
    return StringParseResult::Ok(std::string(it, env.end));
  }

  NoParseResult       ParseDelimiter(std::pair<ParserEnv*, std::string> env_with_delimiter)
  {
    ParserEnv*  env = env_with_delimiter.first;
    const std::string delimiter = env_with_delimiter.second;

    if (std::distance(env->it, env->end) < static_cast<ptrdiff_t>(delimiter.size()))
      return NoParseResult::Error(BitcoinExchange::kIncompleteEntry);
    else if (std::equal(env->it, env->it + delimiter.size(), delimiter.begin()))
    {
      std::advance(env->it, static_cast<ptrdiff_t>(delimiter.size()));
      return NoParseResult::Ok(Nothing());
    }
    else
      return NoParseResult::Error(BitcoinExchange::kInvalidEntry);
  }

  NoParseResult       ParseWhitespaces(ParserEnv& env)
  {
    while (std::isspace(*env.it))
      ++env.it;
    return NoParseResult::Ok(Nothing());
  }

  NoParseResult       ParseEnd(ParserEnv& env)
  {
    if (env.it == env.end)
      return NoParseResult::Ok(Nothing());
    else
      return NoParseResult::Error(BitcoinExchange::kExtraFields);
  }

  NoParseResult       UpdateEnv(std::pair<ParserEnv*, ParserEnv> env_with_new_env)
  {
    *env_with_new_env.first = env_with_new_env.second;
    return NoParseResult::Ok(Nothing());
  }

  StringParseResult   ValidateHeader(std::string header, std::string expected)
  {
    if (expected.empty() || header == expected)
      return StringParseResult::Ok(header);
    else
      return StringParseResult::Error(BitcoinExchange::kWrongHeaders);
  }

} // namespace bitcoin_exchange
