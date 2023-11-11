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

  ////////////////////////////////////////////////////////////////////
  ////////////   ParserEnv action (Use by bitcoinExchange)   ////////////
  ////////////////////////////////////////////////////////////////////

  typedef std::pair<Date, float> Entry;
  typedef Result<BitcoinExchange::Headers, BitcoinExchange::kErrorCode> HeadersParseResult;
  typedef Result<Entry, BitcoinExchange::kErrorCode> EntryParseResult;

  HeadersParseResult  ParseHeaders(ParserEnv& ParserEnv);
  EntryParseResult    ParseEntry(ParserEnv& ParserEnv);

  ////////////////////////////////////////////////////////////
  ////////////   ParserEnv action (implementation)   ////////////
  ////////////////////////////////////////////////////////////

  typedef Result<Date, BitcoinExchange::kErrorCode> DateParseResult;
  typedef Result<float, BitcoinExchange::kErrorCode> RateParseResult;
  typedef Result<int, BitcoinExchange::kErrorCode> IntParseResult;
  typedef Result<struct Nothing, BitcoinExchange::kErrorCode> NoParseResult;

  DateParseResult     ParseDate(ParserEnv& ParserEnv);
  RateParseResult     ParseRate(ParserEnv& ParserEnv);

  IntParseResult      ParseInt(ParserEnv& ParserEnv);
  NoParseResult       ParseDelimiter(ParserEnv& ParserEnv);
  NoParseResult       ParseWhitespaces(ParserEnv& ParserEnv);
  NoParseResult       ParseNewline(ParserEnv& ParserEnv);
  NoParseResult       ParseEnd(ParserEnv& ParserEnv);

  template <typename T>
  NoParseResult     SavesValueTo(T value, T& location)
  {
    location = value;
    return NoParseResult::Ok(Nothing());
  }
} // namespace bitcoin_exchange
