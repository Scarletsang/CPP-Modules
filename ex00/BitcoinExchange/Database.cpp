/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:41:06 by htsang            #+#    #+#             */
/*   Updated: 2023/12/11 22:07:42 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Database.hpp"

#include <map>
#include <exception>
#include <utility>

#include "Date.hpp"
#include "Result.hpp"

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
    else
    {
      rates_[entry.first] = entry.second;
      return kNoError;
    }
  }

  Database::RateResult  Database::get_rate(Date date) const
  {
    if (rates_.empty())
      return RateResult::Error(kEmptyDatabase);
    std::map<Date, float>::const_iterator it = rates_.find(date);
    if (it == rates_.end())
      return RateResult::Error(kInvalidDate);
    else if (it != rates_.begin())
      --it;
    return it->second;
  }

  Database::EntryResult Database::get_closest_entry(Date date) const
  {
    if (rates_.empty())
      return EntryResult::Error(kEmptyDatabase);
    std::map<Date, float>::const_iterator it = rates_.upper_bound(date);
    if (it != rates_.begin())
      --it;
    return EntryResult::Ok(*it);
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

  void  Database::print_error(enum kErrorCode error_code) const
  {
    switch (error_code)
    {
      case kInvalidDate:
        std::cerr << "Invalid date" << std::endl;
        break;
      case kNegativeRate:
        std::cerr << "Negative rate" << std::endl;
        break;
      case kOutOfRangeRate:
        std::cerr << "Out of range rate" << std::endl;
        break;
      case kEmptyDatabase:
        std::cerr << "Empty database" << std::endl;
        break;
      default:
        break;
    }
  }

} // namespace bitcoin_exchange
