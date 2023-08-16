/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:38:07 by htsang            #+#    #+#             */
/*   Updated: 2023/08/16 14:36:21 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <ostream>
#include <cmath>

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

    /* static methods */
    static Fixed&       min(Fixed& a, Fixed& b);
    static Fixed&       max(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

  private:
    int              value_;
    static const int bits_ = 8;
};

std::ostream&  operator<<(std::ostream &out, const Fixed& fixed);

#endif
