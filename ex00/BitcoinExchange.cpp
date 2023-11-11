/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:39:04 by htsang            #+#    #+#             */
/*   Updated: 2023/11/11 18:01:27 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <string>
#include <algorithm>

#include "Date.hpp"
#include "Result.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& other)
  : db_(other.db_) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange&  BitcoinExchange::operator=(BitcoinExchange const& other)
{
  if (this != &other)
    db_ = other.db_;
  return *this;
}

namespace parser
{
  // parse .csv date, exchange rate

  // parse .txt date | exchange rate
  typedef std::pair<Date, float> Entry;
  typedef Result<BitcoinExchange::Headers, BitcoinExchange::kErrorCode> HeadersParseResult;
  typedef Result<bool, BitcoinExchange::kErrorCode> BoolParseResult;
  typedef Result<Entry, BitcoinExchange::kErrorCode> EntryParseResult;

  struct ParserMetaData
  {
    std::string::iterator&  it;
    std::string::iterator&  end;
    std::string             delimiter;
  };

  BoolParseResult  ParseDelimiter(struct ParserMetaData& parser_meta)
  {
    if (parser_meta.end - parser_meta.it < parser_meta.delimiter.length())
      return BoolParseResult::Error(BitcoinExchange::kInvalidEntry);
    else if (std::equal(parser_meta.it, parser_meta.it + parser_meta.delimiter.length(), 
      parser_meta.delimiter.begin(), parser_meta.delimiter.end()))
    {
      parser_meta.it += parser_meta.delimiter.length();
      return BoolParseResult::Ok(true);
    }
    else
      return BoolParseResult::Error(BitcoinExchange::kInvalidEntry);
    return BoolParseResult::Ok(true);
  }

  BoolParseResult  ParseSpaces(struct ParserMetaData& parser_meta)
  {
    while (parser_meta.it != parser_meta.end && std::isspace(*parser_meta.it))
      ++parser_meta.it;
    return BoolParseResult::Ok(true);
  }

  BoolParseResult  CheckEndOfLine(struct ParserMetaData& parser_meta)
  {
    if (parser_meta.it != parser_meta.end && *parser_meta.it != '\n')
      return BoolParseResult::Error(BitcoinExchange::kInvalidEntry);
    return BoolParseResult::Ok(true);
  }

  EntryParseResult ParseDate(Entry entry, struct ParserMetaData& parser_meta)
  {
    Date                  date;
    struct ParserMetaData date_parser_meta(parser_meta);
    date_parser_meta.delimiter = "-";

    ParseDelimiter(date_parser_meta)
      .chain(&ParseSpaces, date_parser_meta);

    return EntryParseResult::Ok(entry);
  }

  EntryParseResult ParseRate(Entry entry, struct ParserMetaData& parser_meta)
  {
    float rate;

    return EntryParseResult::Ok(entry);
  }

  HeadersParseResult ParseHeaders(int, struct ParserMetaData& parser_meta)
  {
    BitcoinExchange::Headers headers;

    return HeadersParseResult::Ok(headers);
  }

  EntryParseResult ParseEntry(int, struct ParserMetaData& parser_meta)
  {
    return ParseDate(std::pair<Date, float>(), parser_meta)
      .chain(&ParseSpaces, parser_meta)
      .chain(&ParseDate, parser_meta)
      .chain(&ParseSpaces, parser_meta)
      .chain(&ParseDelimiter, parser_meta)
      .chain(&ParseSpaces, parser_meta)
      .chain(&ParseRate, parser_meta)
      .chain(&CheckEndOfLine, parser_meta);
  }
} // namespace parser
