/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:39:04 by htsang            #+#    #+#             */
/*   Updated: 2023/11/11 22:20:49 by htsang           ###   ########.fr       */
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

// namespace parser
// {
//   struct Nothing
//   {
//     Nothing() {};
//   };
//   typedef std::pair<Date, float> Entry;
//   typedef Result<BitcoinExchange::Headers, BitcoinExchange::kErrorCode> HeadersParseResult;
//   typedef Result<Entry, BitcoinExchange::kErrorCode> EntryParseResult;
//   typedef Result<Date, BitcoinExchange::kErrorCode> DateParseResult;
//   typedef Result<float, BitcoinExchange::kErrorCode> RateParseResult;
//   typedef Result<int, BitcoinExchange::kErrorCode> IntParseResult;
//   typedef Result<struct Nothing, BitcoinExchange::kErrorCode> NoParseResult;

//   struct ParserMetaData
//   {
//     std::string::iterator&  it;
//     std::string::iterator&  end;
//     std::string             delimiter;
//   };

//   NoParseResult  ParseDelimiter(struct ParserMetaData& parser_meta)
//   {
//     if (parser_meta.end - parser_meta.it < parser_meta.delimiter.length())
//       return NoParseResult::Error(BitcoinExchange::kInvalidEntry);
//     else if (std::equal(parser_meta.it, parser_meta.it + parser_meta.delimiter.length(), 
//       parser_meta.delimiter.begin(), parser_meta.delimiter.end()))
//     {
//       parser_meta.it += parser_meta.delimiter.length();
//       return NoParseResult::Ok(Nothing());
//     }
//     else
//       return NoParseResult::Error(BitcoinExchange::kInvalidEntry);
//     return NoParseResult::Ok(Nothing());
//   }

//   NoParseResult  ParseSpaces(struct ParserMetaData& parser_meta)
//   {
//     while (parser_meta.it != parser_meta.end && std::isspace(*parser_meta.it))
//       ++parser_meta.it;
//     return NoParseResult::Ok(Nothing());
//   }

//   NoParseResult  CheckEndOfLine(struct ParserMetaData& parser_meta)
//   {
//     if (parser_meta.it != parser_meta.end && *parser_meta.it != '\n')
//       return NoParseResult::Error(BitcoinExchange::kInvalidEntry);
//     return NoParseResult::Ok(Nothing());
//   }

//   int Int(std::string& input)
//   {
//     int i = std::atoi(input.c_str());
//     if (i == 0 && input != "0")
//       throw std::invalid_argument("Invalid input");
//     return i;
//   }

//   template <typename T>
//   NoParseResult SavesValueTo(T data, T& location)
//   {
//     location = data;
//     return NoParseResult::Ok(Nothing());
//   }

//   DateParseResult ParseDate(struct ParserMetaData& parser_meta)
//   {
//     Date                  date;
//     struct ParserMetaData date_parser_meta(parser_meta);
//     date_parser_meta.delimiter = "-";

//     ParseDelimiter(date_parser_meta)
//       .chain(&ParseSpaces, date_parser_meta);

//     return DateParseResult::Ok(date);
//   }

//   RateParseResult ParseRate(struct ParserMetaData& parser_meta)
//   {
//     float rate;

//     return RateParseResult::Ok(rate);
//   }

//   HeadersParseResult ParseHeaders(int, struct ParserMetaData& parser_meta)
//   {
//     BitcoinExchange::Headers headers;

//     return HeadersParseResult::Ok(headers);
//   }

//   EntryParseResult ParseEntry(int, struct ParserMetaData& parser_meta)
//   {
//     Entry entry;

//     if (ParseDate(parser_meta)
//       .chain(&SavesValueTo<Date>, entry.first)
//       .chain(&ParseSpaces, parser_meta)
//       .chain(&ParseDelimiter, parser_meta)
//       .chain(&ParseSpaces, parser_meta)
//       .chain(&ParseRate, parser_meta)
//       .chain(&SavesValueTo<float>, entry.second)
//       .chain(&CheckEndOfLine, parser_meta)
//       .is_ok())
//         return EntryParseResult::Ok(entry);
//     return EntryParseResult::Error(BitcoinExchange::kInvalidEntry);
//   }
// } // namespace parser
