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
    std::string::iterator&  it;
    std::string::iterator&  end;

    ParserEnv(std::string::iterator& it, std::string::iterator& end);
    ParserEnv(ParserEnv const& other);
    ParserEnv& operator=(ParserEnv const& other);
  };

  struct ParserSettings
  {
    std::string               delimiter;
    BitcoinExchange::Headers  headers;
  };

  ////////////////////////////////////////////////////////////////////
  ////////////   ParserEnv action (Use by bitcoinExchange)   ////////////
  ////////////////////////////////////////////////////////////////////

  typedef std::pair<Date, float> Entry;
  typedef Result<BitcoinExchange::Headers, BitcoinExchange::kErrorCode> HeadersParseResult;
  typedef Result<Entry, BitcoinExchange::kErrorCode> EntryParseResult;

  HeadersParseResult  ParseHeaders(std::pair<ParserEnv, ParserSettings> env_with_delimiter);
  EntryParseResult    ParseEntry(std::pair<ParserEnv, std::string> env_with_delimiter);

  ////////////////////////////////////////////////////////////
  ////////////   ParserEnv action (implementation)   ////////////
  ////////////////////////////////////////////////////////////

  typedef Result<Date, BitcoinExchange::kErrorCode> DateParseResult;
  typedef Result<float, BitcoinExchange::kErrorCode> RateParseResult;
  typedef Result<int, BitcoinExchange::kErrorCode> IntParseResult;
  typedef Result<Nothing, BitcoinExchange::kErrorCode> NoParseResult;
  typedef Result<std::string, BitcoinExchange::kErrorCode> StringParseResult;

  DateParseResult     ParseDate(ParserEnv& env);
  RateParseResult     ParseRate(ParserEnv& env);

  IntParseResult      ParseInt(ParserEnv& env);
  StringParseResult   ParseString(std::pair<ParserEnv*, std::string> env_with_string);
  NoParseResult       ParseDelimiter(std::pair<ParserEnv*, std::string> env_with_delimiter);
  NoParseResult       ParseWhitespaces(ParserEnv& env);
  NoParseResult       ParseNewline(ParserEnv& env);
  NoParseResult       ParseEnd(ParserEnv& env);

  template <typename T>
  NoParseResult     SavesValueTo(T value, T* location)
  {
    *location = value;
    return NoParseResult::Ok(Nothing());
  }
} // namespace bitcoin_exchange
