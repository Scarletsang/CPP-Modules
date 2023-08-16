/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:38:07 by htsang            #+#    #+#             */
/*   Updated: 2023/08/15 18:19:14 by htsang           ###   ########.fr       */
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

    int   getRawBits() const;
    void  setRawBits(int const raw);

    float toFloat() const;
    int   toInt() const;

  private:
    int              value_;
    static const int bits_ = 8;
};

std::ostream&  operator<<(std::ostream &out, const Fixed& fixed);

#endif