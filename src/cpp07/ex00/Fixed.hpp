/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:38:07 by htsang            #+#    #+#             */
/*   Updated: 2023/10/29 22:57:33 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cmath>

#include <iostream>
#include <ostream>
#include <limits>
#include <exception>

class Fixed
{
  public:
    Fixed();
    Fixed(int const value);
    Fixed(float const value);
    ~Fixed();
    Fixed(const Fixed& fixed);
    const Fixed& operator=(const Fixed& fixed);

    /* getters and setters */

    int   getRawBits() const;
    void  setRawBits(int const raw);

     /* convertion methods */

    float toFloat() const;
    int   toInt() const;

    /* comparation methods */

    bool  operator>(const Fixed& fixed) const;
    bool  operator<(const Fixed& fixed) const;
    bool  operator>=(const Fixed& fixed) const;
    bool  operator<=(const Fixed& fixed) const;
    bool  operator==(const Fixed& fixed) const;
    bool  operator!=(const Fixed& fixed) const;

    /* monoids */

    Fixed operator+(const Fixed& fixed) const;
    Fixed operator-(const Fixed& fixed) const;
    Fixed operator*(const Fixed& fixed) const;
    Fixed operator/(const Fixed& fixed) const;

    /* increment and decrement operators */
    Fixed &operator++();
    Fixed &operator--();
    Fixed operator++(int);
    Fixed operator--(int);

    template <typename T>
    static bool is_convertable(T value)
    {
      return (value <= static_cast<T>(std::numeric_limits<int>::max() >> bits_) &&
              value >= static_cast<T>(std::numeric_limits<int>::min() >> bits_));
    }

    class NotConvertableException : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };

  private:
    int              value_;
    static const int bits_ = 8;
};

std::ostream&  operator<<(std::ostream &out, const Fixed& fixed);
