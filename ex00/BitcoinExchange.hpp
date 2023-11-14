/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:18:51 by htsang            #+#    #+#             */
/*   Updated: 2023/11/14 23:15:44 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#include "BitcoinExchange/Database.hpp"

class BitcoinExchange
{
  public:
    enum  kErrorCode
    {
      kNoError = 0,
      kFileNotFound,
      kEmptyFile,
      kWrongHeaders,
      kIncompleteEntry,
      kInvalidEntry,
      kInvalidDate,
      kExtraFields,
      kNegativeRate,
      kOutOfRangeRate
    };
    struct Headers
    {
      std::string date;
      std::string rate;
    };
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const& other);
    ~BitcoinExchange();

    BitcoinExchange&  operator=(BitcoinExchange const& other);

    kErrorCode  entries_from_file(std::string filename, std::string delimiter, bool silent = false);
    kErrorCode  entry_from_line(std::string line, std::string delimiter, bool silent = false);
    kErrorCode  header_from_line(std::string line, std::string delimiter);
  
  private:
    struct Headers             headers_;
    bitcoin_exchange::Database db_;

    kErrorCode  print_error(kErrorCode error, std::string& line);
};
