/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResultInternal.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:20:02 by htsang            #+#    #+#             */
/*   Updated: 2023/09/12 22:00:40 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ResultInternal.hpp"

#include <string>

namespace parser
{
  ResultInternal::ResultInternal(std::string &string)
  : string_(string),
    position_(0),
    is_valid_(false) {}

  ResultInternal::~ResultInternal() {}

  ResultInternal::ResultInternal(const ResultInternal& value)
    : string_(value.string_),
      position_(value.position_),
      is_valid_(value.is_valid_) {}

  const ResultInternal&  ResultInternal::operator=(const ResultInternal& parser)
  {
    if (this == &parser)
      return *this;
    string_ = parser.string_;
    position_ = parser.position_;
    is_valid_ = parser.is_valid_;
    return *this;
  }

  /* validators */

  bool  ResultInternal::is_valid() const
  {
    return is_valid_;
  }
  bool  ResultInternal::is_end() const
  {
    return position_ >= string_.size();
  }

  /* getters */

  std::string ResultInternal::string() const
  {
    return string_.substr(position_);
  }

  /* setters */

  void  ResultInternal::set_valid(bool is_valid)
  {
    is_valid_ = is_valid;
  }

  void  ResultInternal::advance(size_t n)
  {
    position_ += n;
  }

}
