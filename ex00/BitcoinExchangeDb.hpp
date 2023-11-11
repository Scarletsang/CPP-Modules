/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchangeDb.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:03:51 by htsang            #+#    #+#             */
/*   Updated: 2023/11/11 00:08:36 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <exception>
#include <utility>

#include "Date.hpp"

class BitcoinExchangeDb
{
  public:
    enum  kErrorCode
    {
      kNoError = 0,
      kInvalidDate,
      kNegativeRate,
      kOutOfRangeRate
    };
    BitcoinExchangeDb();
    BitcoinExchangeDb(BitcoinExchangeDb const& other);
    ~BitcoinExchangeDb();

    BitcoinExchangeDb&  operator=(BitcoinExchangeDb const& other);

    enum  kErrorCode        set_entry(Date date, float rate);
    enum  kErrorCode        set_entry(std::pair<Date, float> entry);
    float                   get_rate(Date date) const;
    std::pair<Date, float>  get_closest_rate(Date date) const;

    class NoRateException : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };
  
  private:
    std::map<Date, float>  rates_;
};
