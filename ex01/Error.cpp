/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:50:53 by htsang            #+#    #+#             */
/*   Updated: 2023/12/05 23:53:04 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Error.hpp"

#include <iostream>

Error::Error() : code_(kOk) {}

Error::Error(kErrorCode code) : code_(code) {}

Error::Error(Error const& other) : code_(other.code_) {}

Error& Error::operator=(Error const& other)
{
  if (this != &other)
    this->code_ = other.code_;
  return *this;
}

Error::~Error() {}

Error::kErrorCode Error::code() const
{
  return this->code_;
}

std::ostream& operator<<(std::ostream& os, Error const& e)
{
  switch (e.code())
  {
    case Error::kOk:
      break;
    case Error::kInvalidNumber:
      os << "Error: Invalid number";
      break;
    case Error::kInvalidOperation:
      os << "Error: Invalid operation";
      break;
    case Error::kInvalidOperand:
      os << "Error: Invalid operand";
      break;
    case Error::kStackEmpty:
      os << "Error: Stack empty";
      break;
    case Error::kAmbiguous:
      os << "Error: Ambiguous result";
      break;
    default:
      os << "Error: Unknown error";
      break;
  }
  return os;
}
