/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:39:04 by htsang            #+#    #+#             */
/*   Updated: 2023/11/14 23:20:41 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>

#include "BitcoinExchange/Parser.hpp"
#include "Date.hpp"
#include "Result.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& other)
  : headers_(other.headers_), db_(other.db_) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange&  BitcoinExchange::operator=(BitcoinExchange const& other)
{
  if (this != &other)
  {
    headers_ = other.headers_;
    db_ = other.db_;
  }
  return *this;
}

BitcoinExchange::kErrorCode BitcoinExchange::entries_from_file(std::string filename, 
                                                    std::string delimiter,
                                                    bool silent = false)
{
  std::ifstream file(filename);

  if (!file.is_open())
    return silent ? kFileNotFound : print_error(kFileNotFound, filename);
  std::string line;
  kErrorCode  error_code = kNoError;
  if (!std::getline(file, line))
    return silent ? kEmptyFile : print_error(kEmptyFile, line);
  else if (header_from_line(line, delimiter) != kNoError)
    return silent ? kWrongHeaders : print_error(kWrongHeaders, line);
  while (std::getline(file, line))
  {
    if ((error_code = entry_from_line(line, delimiter, silent)) != kNoError)
      return silent ? error_code : print_error(error_code, line);
  }
  file.close();
  return error_code;
}

BitcoinExchange::kErrorCode BitcoinExchange::entry_from_line(std::string line,
                                                    std::string delimiter,
                                                    bool silent = false)
{
  bitcoin_exchange::ParserEnv env(line.begin(), line.end());

  bitcoin_exchange::EntryParseResult result = \
    bitcoin_exchange::ParseEntry(std::make_pair(&env, delimiter));
  if (result.is_ok())
  {
    db_.set_entry(result.value());
    return kNoError;
  }
  else
    return result.error();
}

BitcoinExchange::kErrorCode  BitcoinExchange::header_from_line(std::string line,
                                                               std::string delimiter)
{
  bitcoin_exchange::ParserSettings settings(delimiter, headers_);
  bitcoin_exchange::ParserEnv      env(line.begin(), line.end());

  bitcoin_exchange::HeadersParseResult result = \
    bitcoin_exchange::ParseHeaders(std::make_pair(&env, settings));
  if (result.is_ok())
  {
    headers_ = result.value();
    return kNoError;
  }
  else
    return result.error();
}

BitcoinExchange::kErrorCode  BitcoinExchange::print_error(kErrorCode error, std::string& line)
{
  switch (error)
  {
    case kFileNotFound:
      std::cerr << "Error: " << strerror(errno) << std::endl;
      break;
    case kEmptyFile:
      std::cerr << "Error: Empty file" << std::endl;
      break;
    case kWrongHeaders:
      std::cerr << "Error: Wrong headers" << std::endl;
      break;
    case kIncompleteEntry:
      std::cerr << "Error: Incomplete entry: " << line << std::endl;
      break;
    case kInvalidEntry:
      std::cerr << "Error: Invalid entry: " << line << std::endl;
      break;
    case kInvalidDate:
      std::cerr << "Error: Invalid date: " << line << std::endl;
      break;
    case kExtraFields:
      std::cerr << "Error: Extra fields: " << line << std::endl;
      break;
    case kNegativeRate:
      std::cerr << "Error: Negative rate: " << line << std::endl;
      break;
    case kOutOfRangeRate:
      std::cerr << "Error: Out of range rate: " << line << std::endl;
      break;
    default:
      break;
  }
  return error;
}
