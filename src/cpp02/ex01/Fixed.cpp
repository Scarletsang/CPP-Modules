/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:37:57 by htsang            #+#    #+#             */
/*   Updated: 2023/09/12 19:53:07 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cassert>
#include <cmath>

#include <limits>
#include <iostream>

Fixed::Fixed(): value_(0)
{
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value)
{
  std::cout << "Int constructor called" << std::endl;
  assert(Fixed::is_convertable(value));
  value_ = value << bits_;
}

Fixed::Fixed(float const value)
{
  std::cout << "Float constructor called" << std::endl;
   assert(Fixed::is_convertable(value));
  value_ = static_cast<int>(roundf(value * (1 << bits_)));
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
  value_ = fixed.value_;
  return *this;
}

int Fixed::getRawBits() const
{
  return value_;
}

void  Fixed::setRawBits(int const raw)
{
  value_ = raw;
}

float Fixed::toFloat() const
{
  return (static_cast<float>(value_) / static_cast<float>(1 << bits_));
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
