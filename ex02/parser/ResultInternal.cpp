/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResultInternal.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:20:02 by htsang            #+#    #+#             */
/*   Updated: 2023/09/13 23:01:01 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ResultInternal.hpp"

#include <string>

namespace parser
{
  ResultInternal::ResultInternal()
  : string_(std::string()),
    is_valid_(false) {}

  ResultInternal::ResultInternal(std::string string)
  : string_(string),
    is_valid_(false) {}

  ResultInternal::~ResultInternal() {}

  ResultInternal::ResultInternal(const ResultInternal& value)
    : string_(value.string_),
      is_valid_(value.is_valid_) {}

  const ResultInternal&  ResultInternal::operator=(const ResultInternal& value)
  {
    if (this == &value)
      return *this;
    string_ = value.string_;
    is_valid_ = value.is_valid_;
    return *this;
  }

  /* validators */

  bool  ResultInternal::is_valid() const
  {
    return is_valid_;
  }
  bool  ResultInternal::is_end() const
  {
    return string_.empty();
  }

  /* getters */

  std::string &ResultInternal::string() const
  {
    return const_cast<std::string &>(string_);
  }

  /* setters */

  void  ResultInternal::set_valid(bool is_valid)
  {
    is_valid_ = is_valid;
  }

  void  ResultInternal::set_string(std::string string)
  {
    string_ = string;
  }

  void  ResultInternal::advance(size_t n)
  {
    string_ = string_.substr(n);
  }

}
