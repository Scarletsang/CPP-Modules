/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchangeDb.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:31:31 by htsang            #+#    #+#             */
/*   Updated: 2023/11/11 00:14:15 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchangeDb.hpp"

#include <map>
#include <exception>
#include <utility>

#include "Date.hpp"

BitcoinExchangeDb::BitcoinExchangeDb() {}

BitcoinExchangeDb::BitcoinExchangeDb(BitcoinExchangeDb const& other)
  : rates_(other.rates_) {}

BitcoinExchangeDb::~BitcoinExchangeDb() {}

BitcoinExchangeDb&  BitcoinExchangeDb::operator=(BitcoinExchangeDb const& other)
{
  if (this != &other)
    rates_ = other.rates_;
  return *this;
}

BitcoinExchangeDb::kErrorCode  BitcoinExchangeDb::set_entry(Date date, float rate)
{
  if (!date.is_valid())
    return kInvalidDate;
  else if (rate < 0)
    return kNegativeRate;
  else if (rate > 1000)
    return kOutOfRangeRate;
  rates_[date] = rate;
  return kNoError;
}

BitcoinExchangeDb::kErrorCode  BitcoinExchangeDb::set_entry(std::pair<Date, float> entry)
{
  if (!entry.first.is_valid())
    return kInvalidDate;
  else if (entry.second < 0)
    return kNegativeRate;
  else if (entry.second > 1000)
    return kOutOfRangeRate;
  rates_[entry.first] = entry.second;
  return kNoError;
}

float BitcoinExchangeDb::get_rate(Date date) const
{
  std::map<Date, float>::const_iterator it = rates_.find(date);
  if (it == rates_.end())
    throw NoRateException();
  return it->second;
}

std::pair<Date, float> BitcoinExchangeDb::get_closest_rate(Date date) const
{
  std::map<Date, float>::const_iterator it = rates_.lower_bound(date);
  if (it == rates_.end())
    throw NoRateException();
  return *it;
}

const char* BitcoinExchangeDb::NoRateException::what() const throw()
{
  return "The Bitcoin exchange database is empty.";
}
