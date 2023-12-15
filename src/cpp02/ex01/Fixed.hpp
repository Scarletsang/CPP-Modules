/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:38:07 by htsang            #+#    #+#             */
/*   Updated: 2023/09/18 19:27:06 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cmath>

#include <iostream>
#include <ostream>
#include <limits>

class Fixed
{
  public:
    Fixed();
    Fixed(int const value);
    Fixed(float const value);
    ~Fixed();
    Fixed(const Fixed& fixed);
    const Fixed& operator=(const Fixed& fixed);

    int   getRawBits() const;
    void  setRawBits(int const raw);

    float toFloat() const;
    int   toInt() const;

    template <typename T>
    static bool is_convertable(T value)
    {
      return (value <= static_cast<T>(std::numeric_limits<int>::max() >> bits_) &&
              value >= static_cast<T>(std::numeric_limits<int>::min() >> bits_));
    }

  private:
    int              value_;
    static const int bits_ = 8;
};

std::ostream&  operator<<(std::ostream &out, const Fixed& fixed);
