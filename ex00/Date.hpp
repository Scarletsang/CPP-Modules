/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:27:19 by htsang            #+#    #+#             */
/*   Updated: 2023/11/11 00:06:36 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Date
{
  public:
    Date();
    Date(int year, int month, int day);
    Date(const Date& other);
    ~Date();

    Date& operator=(const Date& other);
    bool operator<(const Date& other) const;

    int year() const;
    int month() const;
    int day() const;

    bool  is_leap_year() const;
    bool  is_valid() const;

  private:
    int year_;
    int month_;
    int day_;
};
