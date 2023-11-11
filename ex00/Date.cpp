/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:27:29 by htsang            #+#    #+#             */
/*   Updated: 2023/11/11 05:00:45 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::Date()
  : year_(-1), month_(-1), day_(-1) {}

Date::Date(int year, int month, int day)
  : year_(year), month_(month), day_(day)
{
  if (!is_valid())
  {
    year_ = -1;
    month_ = -1;
    day_ = -1;
  }
}

Date::Date(const Date& other)
  : year_(other.year()), month_(other.month()), day_(other.day()) {}

Date::~Date() {}

Date& Date::operator=(const Date& other)
{
  if (this != &other)
  {
    year_ = other.year();
    month_ = other.month();
    day_ = other.day();
  }
  return *this;
}

bool  Date::operator<(const Date& other) const
{
  if (year_ < other.year())
    return true;
  else if (year_ > other.year())
    return false;
  else if (month_ < other.month())
    return true;
  else if (month_ > other.month())
    return false;
  else
    return (day_ < other.day());
}

int Date::year() const
{
  return year_;
}

int Date::month() const
{
  return month_;
}

int Date::day() const
{
  return day_;
}

void  Date::set_year(int year)
{
  year_ = year;
}

void  Date::set_month(int month)
{
  month_ = month;
}

void  Date::set_day(int day)
{
  day_ = day;
}

bool  Date::is_leap_year() const
{
  if (year_ % 4 != 0)
    return false;
  else if (year_ % 100 != 0)
    return true;
  else if (year_ % 400 != 0)
    return false;
  else
    return true;
}

bool  Date::is_valid() const
{
  if (year_ < 0 || month_ < 0 || day_ < 0)
    return false;
  else if (month_ > 12)
    return false;
  else if (day_ > 31)
    return false;
  else if (month_ == 2 && day_ > 29)
    return false;
  else if (month_ == 2 && day_ == 29 && !is_leap_year())
    return false;
  else if ((month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11) && day_ > 30)
    return false;
  else
    return true;
}
