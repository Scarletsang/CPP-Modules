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

#include "ParserEnv.hpp"

#include <string>

#include "Result.hpp"
#include "Date.hpp"
#include "BitcoinExchange.hpp"

namespace bitcoin_exchange
{
  ////////////////////////////////////////////////
  ////////////   ParserEnv environment   ////////////
  ////////////////////////////////////////////////

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

  ////////////////////////////////////////////////////////////////////
  ////////////   ParserEnv action (Use by bitcoinExchange)   ////////////
  ////////////////////////////////////////////////////////////////////

  HeadersParseResult  ParseHeaders(ParserEnv& parser_with_delimiter)
  {
    BitcoinExchange::Headers headers;

    return HeadersParseResult::Ok(headers);
  }

  EntryParseResult    ParseEntry(ParserEnv& parser_with_delimiter)
  {
    Entry entry;
    ParserEnv<Nothing> ParserEnv(parser_with_delimiter);

    if (ParseDate(ParserEnv)
      .chain(&SavesValueTo<Date>, entry.first)
      .chain(&ParseWhitespaces, ParserEnv)
      .chain(&ParseDelimiter, parser_with_delimiter)
      .chain(&ParseWhitespaces, ParserEnv)
      .chain(&ParseRate, ParserEnv)
      .chain(&SavesValueTo<float>, entry.second)
      .chain(&ParseEnd)
      .is_ok())
        return EntryParseResult::Ok(entry);
    return EntryParseResult::Error(BitcoinExchange::kInvalidEntry); 
  }
  ////////////////////////////////////////////////////////////
  ////////////   ParserEnv action (implementation)   ////////////
  ////////////////////////////////////////////////////////////

  ParserEnv::DateParseResult   ParserEnv::parse_date()
  {
    Date date;

    if (parse_int()
      .chain(&ParserEnv::saves_value_to<int>, date.day)
      .chain(&ParserEnv::parse_delimiter, "-")
      .chain(&ParserEnv::parse_int)
      .chain(&ParserEnv::saves_value_to<int>, date.month)
      .chain(&ParserEnv::parse_delimiter, "-")
      .chain(&ParserEnv::parse_int)
      .chain(&ParserEnv::saves_value_to<int>, date.year)
      .is_ok())
        return DateParseResult::Ok(date);
    return DateParseResult::Error(BitcoinExchange::kInvalidDate);
  }
} // namespace bitcoin_exchange
