/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:37:57 by htsang            #+#    #+#             */
/*   Updated: 2023/09/14 19:30:47 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cassert>
#include <cmath>

#include <limits>
#include <iostream>

//////////////////////////////////////
////////////   debugger   ////////////
//////////////////////////////////////

static void  FixedDebugger(const char *message)
{
#ifdef DEBUG
  std::cout << message << std::endl;
#else
  (void)message;
#endif
}

/////////////////////////////////////////////////////////
////////////   constructors and destructor   ////////////
/////////////////////////////////////////////////////////

Fixed::Fixed(): value_(0)
{
  FixedDebugger("Default constructor called");
}

Fixed::Fixed(int const value)
{
  FixedDebugger("Int constructor called");
  assert(Fixed::is_convertable(value));
  value_ = value << bits_;
}

Fixed::Fixed(float const value)
{
  FixedDebugger("Float constructor called");
  assert(Fixed::is_convertable(value));
  value_ = static_cast<int>(roundf(value * (1 << bits_)));
}

Fixed::~Fixed()
{
  FixedDebugger("Destructor called");
}

////////////////////////////////////////////////////////////////////////////
////////////   copy constructor and copy assignation operator   ////////////
////////////////////////////////////////////////////////////////////////////

Fixed::Fixed(const Fixed& fixed) : value_(fixed.value_)
{
  FixedDebugger("Copy constructor called");
}

const Fixed&  Fixed::operator=(const Fixed& fixed)
{
  FixedDebugger("Copy assignation operator called");
  value_ = fixed.value_;
  return *this;
}

/////////////////////////////////////////////////
////////////   getters and setters   ////////////
/////////////////////////////////////////////////

int Fixed::getRawBits() const
{
  return value_;
}

void  Fixed::setRawBits(int const raw)
{
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
  Fixed added;

  added.setRawBits(value_ + fixed.value_);
  return (added);
}

Fixed Fixed::operator-(const Fixed& fixed) const
{
  Fixed subtracted;

  subtracted.setRawBits(value_ - fixed.value_);
  return (subtracted);
}

Fixed Fixed::operator*(const Fixed& fixed) const
{
  Fixed multiplied;

  multiplied.setRawBits(static_cast<float>((static_cast<long>(value_) * static_cast<long>(fixed.value_)) >> bits_));
  return (multiplied);
}

Fixed Fixed::operator/(const Fixed& fixed) const
{
  Fixed divided;

  divided.setRawBits(static_cast<float>(static_cast<long>(value_ << bits_) / static_cast<long>(fixed.value_)));
  return (divided);
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
