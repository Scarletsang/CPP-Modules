/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:37:57 by htsang            #+#    #+#             */
/*   Updated: 2023/07/24 15:18:04 by htsang           ###   ########.fr       */
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
  assert(value < (std::numeric_limits<int>::max() >> bits_));
  assert(value > (std::numeric_limits<int>::min() >> bits_));
  std::cout << "Int constructor called" << std::endl;
  value_ = value << bits_;
}

Fixed::Fixed(float const value)
{
  std::cout << "Float constructor called" << std::endl;
  // get the exponent
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

}

int   Fixed::toInt() const
{

}

std::ostream&  operator<<(std::ostream &out, const Fixed& fixed)
{

  return out;
}
