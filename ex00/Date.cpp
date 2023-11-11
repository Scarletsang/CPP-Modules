/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:27:29 by htsang            #+#    #+#             */
/*   Updated: 2023/11/11 22:31:07 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::Date()
  : year(-1), month(-1), day(-1) {}

Date::Date(int year, int month, int day)
  : year(year), month(month), day(day)
{
  if (!is_valid())
  {
    year = -1;
    month = -1;
    day = -1;
  }
}

Date::Date(const Date& other)
  : year(other.year), month(other.month), day(other.day) {}

Date& Date::operator=(const Date& other)
{
  if (this != &other)
  {
    year = other.year;
    month = other.month;
    day = other.day;
  }
  return *this;
}

bool  Date::operator<(const Date& other) const
{
  if (year < other.year)
    return true;
  else if (year > other.year)
    return false;
  else if (month < other.month)
    return true;
  else if (month > other.month)
    return false;
  else
    return (day < other.day);
}

bool  Date::is_leap_year() const
{
  if (year % 4 != 0)
    return false;
  else if (year % 100 != 0)
    return true;
  else if (year % 400 != 0)
    return false;
  else
    return true;
}

bool  Date::is_valid() const
{
  if (year < 0 || month < 0 || day < 0)
    return false;
  else if (month > 12)
    return false;
  else if (day > 31)
    return false;
  else if (month == 2 && day > 29)
    return false;
  else if (month == 2 && day == 29 && !is_leap_year())
    return false;
  else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    return false;
  else
    return true;
}
