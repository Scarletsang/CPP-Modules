/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 00:18:51 by htsang            #+#    #+#             */
/*   Updated: 2023/11/11 02:39:09 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#include "BitcoinExchangeDb.hpp"

class BitcoinExchange
{
  public:
    enum  kErrorCode
    {
      kNoError = 0,
      kWrongHeaders,
      kIncompleteEntry,
      kInvalidEntry,
      kInvalidDate,
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

    enum  kErrorCode entries_from_file(std::string filename, std::string delimiter, bool silent = false);
    enum  kErrorCode entries_from_line(std::string line, std::string delimiter, bool silent = false);
  
  private:
    struct Headers    headers_;
    BitcoinExchangeDb db_;
};