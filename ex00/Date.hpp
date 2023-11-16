/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:27:19 by htsang            #+#    #+#             */
/*   Updated: 2023/11/16 16:42:03 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

struct Date
{
  int year;
  int month;
  int day;

  Date();
  Date(const Date& other);
  Date(int year, int month, int day);
  Date& operator=(const Date& other);
  bool operator<(const Date& other) const;
  bool  is_leap_year() const;
  bool  is_valid() const;
};

std::ostream& operator<<(std::ostream& os, const Date& date);
