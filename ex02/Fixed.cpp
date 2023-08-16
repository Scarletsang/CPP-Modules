/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:37:57 by htsang            #+#    #+#             */
/*   Updated: 2023/08/16 12:02:16 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cassert>
#include <cmath>

#include <limits>
#include <iostream>

/////////////////////////////////////////////////////////
////////////   constructors and destructor   ////////////
/////////////////////////////////////////////////////////

Fixed::Fixed(): value_(0)
{
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value)
{
  std::cout << "Int constructor called" << std::endl;
  assert(value < (std::numeric_limits<int>::max() >> bits_));
  assert(value > (std::numeric_limits<int>::min() >> bits_));
  value_ = value << bits_;
}

Fixed::Fixed(float const value)
{
  std::cout << "Float constructor called" << std::endl;
  assert(value <= static_cast<float>(std::numeric_limits<int>::max() >> bits_));
  assert(value >= static_cast<float>(std::numeric_limits<int>::min() >> bits_));
  value_ = static_cast<int>(roundf(value * (1 << bits_)));
}

Fixed::~Fixed()
{
  std::cout << "Destructor called" << std::endl;
}

////////////////////////////////////////////////////////////////////////////
////////////   copy constructor and copy assignation operator   ////////////
////////////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////
////////////   getters and setters   ////////////
/////////////////////////////////////////////////

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

////////////////////////////////////////////////
////////////   convertion methods   ////////////
////////////////////////////////////////////////

float Fixed::toFloat() const
{
  return (static_cast<float>(value_) / static_cast<float>(1 << bits_));
}

int   Fixed::toInt() const
{
  return (value_ >> bits_);
}

/////////////////////////////////////////////////
////////////   comparation methods   ////////////
/////////////////////////////////////////////////

bool  Fixed::operator>(const Fixed& fixed) const
{
  return (value_ > fixed.value_);
}

bool  Fixed::operator<(const Fixed& fixed) const
{
  return (value_ < fixed.value_);
}

bool  Fixed::operator>=(const Fixed& fixed) const
{
  return (value_ >= fixed.value_);
}

bool  Fixed::operator<=(const Fixed& fixed) const
{
  return (value_ <= fixed.value_);
}

bool  Fixed::operator==(const Fixed& fixed) const
{
  return (value_ == fixed.value_);
}

bool  Fixed::operator!=(const Fixed& fixed) const
{
  return (value_ != fixed.value_);
}

/////////////////////////////////////
////////////   monoids   ////////////
/////////////////////////////////////

Fixed Fixed::operator+(const Fixed& fixed) const
{
  return (Fixed(value_ + fixed.value_));
}

Fixed Fixed::operator-(const Fixed& fixed) const
{
  return (Fixed(value_ - fixed.value_));
}

Fixed Fixed::operator*(const Fixed& fixed) const
{
  return (Fixed(value_ * fixed.value_));
}

Fixed Fixed::operator/(const Fixed& fixed) const
{
  return (Fixed(value_ / fixed.value_));
}

///////////////////////////////////////////////////////////////
////////////   increment and decrement operators   ////////////
///////////////////////////////////////////////////////////////

Fixed &Fixed::operator++()
{
  ++value_;
  return (*this);
}

Fixed &Fixed::operator--()
{
  --value_;
  return (*this);
}

Fixed Fixed::operator++(int)
{
  Fixed copy(*this);

  ++value_;
  return (copy);
}

Fixed Fixed::operator--(int)
{
  Fixed copy(*this);

  --value_;
  return (copy);
}

////////////////////////////////////////////
////////////   static methods   ////////////
////////////////////////////////////////////

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
  if (a < b)
    return a;
  else
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
  if (a > b)
    return a;
  else
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
  if (a < b)
    return a;
  else
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
  if (a > b)
    return a;
  else
    return b;
}

std::ostream&  operator<<(std::ostream &out, const Fixed& fixed)
{
  out << fixed.toFloat();
  return out;
}
