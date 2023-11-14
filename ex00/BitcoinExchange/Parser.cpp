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

#include <string>
#include <utility>

#include "Result.hpp"
#include "Date.hpp"
#include "BitcoinExchange.hpp"

namespace bitcoin_exchange
{
  ///////////////////////////////////////////////////
  ////////////   ParserEnv environment   ////////////
  ///////////////////////////////////////////////////

  ParserEnv::ParserEnv(std::string::iterator& it, std::string::iterator& end)
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

  ///////////////////////////////////////////////////////////////////////
  ////////////   ParserEnv action (Use by bitcoinExchange)   ////////////
  ///////////////////////////////////////////////////////////////////////

  HeadersParseResult  ParseHeaders(std::pair<ParserEnv, ParserSettings> env_with_delimiter)
  {
    BitcoinExchange::Headers headers;
    ParserEnv&               env = env_with_delimiter.first;

    if (ParseString(std::make_pair(&env, env_with_delimiter.second.headers.date))
      .chain(&ParseWhitespaces, env)
      .chain(&ParseDelimiter, std::make_pair(&env, env_with_delimiter.second.delimiter))
      .chain(&ParseWhitespaces, env)
      .chain(&ParseString, std::make_pair(&env, env_with_delimiter.second.headers.rate))
      .chain(&ParseEnd, env)
      .is_ok())
      return HeadersParseResult::Ok(headers);
    return HeadersParseResult::Error(BitcoinExchange::kWrongHeaders);
  }

  EntryParseResult    ParseEntry(std::pair<ParserEnv, std::string> env_with_delimiter)
  {
    Entry       entry;
    ParserEnv&  env = env_with_delimiter.first;

    if (ParseDate(env)
      .chain(&SavesValueTo<Date>, &entry.first)
      .chain(&ParseWhitespaces, env)
      .chain(&ParseDelimiter, std::make_pair(&env, env_with_delimiter.second))
      .chain(&ParseWhitespaces, env)
      .chain(&ParseRate, env)
      .chain(&SavesValueTo<float>, &entry.second)
      .chain(&ParseEnd, env)
      .is_ok())
        return EntryParseResult::Ok(entry);
    return EntryParseResult::Error(BitcoinExchange::kInvalidEntry); 
  }

  ///////////////////////////////////////////////////////////////
  ////////////   ParserEnv action (implementation)   ////////////
  ///////////////////////////////////////////////////////////////

  DateParseResult   ParseDate(ParserEnv& env)
  {
    Date  date;

    if (ParseInt(env)
      .chain(&SavesValueTo<int>, &date.day)
      .chain(&ParseDelimiter, std::make_pair(&env, std::string("-")))
      .chain(&ParseInt, env)
      .chain(&SavesValueTo<int>, &date.month)
      .chain(&ParseDelimiter, std::make_pair(&env, std::string("-")))
      .chain(&ParseInt, env)
      .chain(&SavesValueTo<int>, &date.year)
      .is_ok())
        return DateParseResult::Ok(date);
    return DateParseResult::Error(BitcoinExchange::kInvalidDate);
  }

  RateParseResult   ParseRate(ParserEnv& env)
  {
    char* endptr;
    errno = 0;
    double rate = std::strtod(&(*env.it), &endptr);
    if (errno == ERANGE || 
      ((static_cast<double>(std::numeric_limits<float>::max()) < rate) &&
      (rate < static_cast<double>(-std::numeric_limits<float>::max()))))
      return RateParseResult::Error(BitcoinExchange::kOutOfRangeRate);
    else if (rate < 0)
      return RateParseResult::Error(BitcoinExchange::kNegativeRate);
    else
    {
      env.it += (endptr - &*env.it);
      return RateParseResult::Ok(static_cast<float>(rate));
    }
  }
} // namespace bitcoin_exchange
