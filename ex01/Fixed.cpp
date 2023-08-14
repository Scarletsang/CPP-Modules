/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:37:57 by htsang            #+#    #+#             */
/*   Updated: 2023/08/14 16:28:37 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cassert>

#include <iostream>

Fixed::Fixed(): value_(0)
{
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value)
{
  std::cout << "Int constructor called" << std::endl;
  assert(value < (std::numeric_limits<int>::max() >> bits_));
  assert(value > (std::numeric_limits<int>::min() >> bits_));
  setRawBits(value << bits_);
}

Fixed::Fixed(float const value)
{
  std::cout << "Float constructor called" << std::endl;
  assert(value <= static_cast<float>(std::numeric_limits<int>::max() >> bits_));
  assert(value >= static_cast<float>(std::numeric_limits<int>::min() >> bits_));
  setRawBits(static_cast<int>(round(value * (1 << bits_))));
}

Fixed::~Fixed()
{
  std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed) : value_(fixed.value_)
{
  std::cout << "Copy constructor called" << std::endl;
}

const Fixed&  Fixed::operator=(const Fixed& fixed)
{
  std::cout << "Copy assignation operator called" << std::endl;
  setRawBits(fixed.getRawBits());
  return *this;
}

int Fixed::getRawBits() const
{
  std::cout << "getRawBits member function called" << std::endl;
  return value_;
}

void  Fixed::setRawBits(int const raw)
{
  std::cout << "setRawBits member function called" << std::endl;
  value_ = raw;
}

float Fixed::toFloat() const
{
  return ((float)value_ / (float)(1 << bits_));
}

int   Fixed::toInt() const
{
  return (value_ >> bits_);
}

std::ostream&  operator<<(std::ostream &out, const Fixed& fixed)
{
  out << fixed.toFloat();
  return out;
}
