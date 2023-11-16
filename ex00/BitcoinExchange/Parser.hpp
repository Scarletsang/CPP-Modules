/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParserEnv.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:36:59 by htsang            #+#    #+#             */
/*   Updated: 2023/11/11 23:30:36 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <utility>

#include "Result.hpp"
#include "Date.hpp"
#include "BitcoinExchange.hpp"

namespace bitcoin_exchange
{
  struct Nothing
  {
    Nothing() {};
  };

  ////////////////////////////////////////////////
  ////////////   parser environment   ////////////
  ////////////////////////////////////////////////

  struct ParserEnv
  {
    std::string::iterator  it;
    std::string::iterator  end;

    ParserEnv(std::string::iterator it, std::string::iterator end);
    ParserEnv(ParserEnv const& other);
    ParserEnv& operator=(ParserEnv const& other);
  };

  struct ParserSettings
  {
    std::string               delimiter;
    BitcoinExchange::Headers  headers;
    float                     max_rate;

    ParserSettings(std::string delimiter, BitcoinExchange::Headers headers, float max_rate);
  };

  ////////////////////////////////////////////////////////////////////
  ////////////   ParserEnv action (Use by bitcoinExchange)   ////////////
  ////////////////////////////////////////////////////////////////////

  typedef std::pair<Date, float> Entry;
  typedef Result<BitcoinExchange::Headers, BitcoinExchange::kErrorCode> HeadersParseResult;
  typedef Result<Entry, BitcoinExchange::kErrorCode> EntryParseResult;

  HeadersParseResult  ParseHeaders(std::pair<ParserEnv*, ParserSettings> env_with_delimiter);
  EntryParseResult    ParseEntry(std::pair<ParserEnv*, ParserSettings> env_with_delimiter);

  ////////////////////////////////////////////////////////////
  ////////////   ParserEnv action (implementation)   ////////////
  ////////////////////////////////////////////////////////////

  typedef Result<Date, BitcoinExchange::kErrorCode> DateParseResult;
  typedef Result<float, BitcoinExchange::kErrorCode> RateParseResult;
  typedef Result<int, BitcoinExchange::kErrorCode> IntParseResult;
  typedef Result<Nothing, BitcoinExchange::kErrorCode> NoParseResult;
  typedef Result<std::string, BitcoinExchange::kErrorCode> StringParseResult;

  DateParseResult     ParseDate(ParserEnv& env);
  RateParseResult     ParseRate(std::pair<ParserEnv*, float> env_with_maximum_rate);

  IntParseResult      ParseInt(ParserEnv& env);
  StringParseResult   ParseUntilDelimiter(std::pair<ParserEnv*, std::string> env_with_delimiter);
  StringParseResult   ParseUntilEof(ParserEnv& env);
  NoParseResult       ParseDelimiter(std::pair<ParserEnv*, std::string> env_with_delimiter);
  NoParseResult       ParseWhitespaces(ParserEnv& env);
  NoParseResult       ParseEnd(ParserEnv& env);

  StringParseResult   TrimString(std::string string, ParserEnv& env);
  StringParseResult   ValidateHeader(std::string header, std::string expected);

  NoParseResult       UpdateEnv(std::pair<ParserEnv*, ParserEnv> env_with_new_env);

  template <typename T>
  NoParseResult     SavesValueTo(T value, T* location)
  {
    *location = value;
    return NoParseResult::Ok(Nothing());
  }

  template <typename T>
  Result<T, BitcoinExchange::kErrorCode> Return(T value)
  {
    return Result<T, BitcoinExchange::kErrorCode>::Ok(value);
  }
} // namespace bitcoin_exchange
