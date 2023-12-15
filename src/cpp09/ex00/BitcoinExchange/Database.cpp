/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:41:06 by htsang            #+#    #+#             */
/*   Updated: 2023/12/05 21:58:21 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Database.hpp"

#include <map>
#include <exception>
#include <utility>

#include "Date.hpp"

namespace bitcoin_exchange
{
  Database::Database() {}

  Database::Database(Database const& other)
    : rates_(other.rates_) {}

  Database::~Database() {}

  Database&  Database::operator=(Database const& other)
  {
    if (this != &other)
      rates_ = other.rates_;
    return *this;
  }

  Database::kErrorCode  Database::set_entry(Date date, float rate)
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

  Database::kErrorCode  Database::set_entry(std::pair<Date, float> entry)
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

  float Database::get_rate(Date date) const
  {
    std::map<Date, float>::const_iterator it = rates_.find(date);
    if (it == rates_.end())
      throw NoRateException();
    return it->second;
  }

  std::pair<Date, float> Database::get_closest_entry(Date date) const
  {
    std::map<Date, float>::const_iterator it = rates_.lower_bound(date);
    if (it == rates_.end())
      throw NoRateException();
    return *it;
  }

  bool  Database::is_empty() const
  {
    return rates_.empty();
  }

  size_t  Database::size() const
  {
    return rates_.size();
  }

  Database::const_iterator  Database::begin() const
  {
    return rates_.begin();
  }

  Database::const_iterator  Database::end() const
  {
    return rates_.end();
  }

  const char* Database::NoRateException::what() const throw()
  {
    return "The Bitcoin exchange database is empty.";
  }

} // namespace bitcoin_exchange
