/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TokenizerBase.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:37:33 by htsang            #+#    #+#             */
/*   Updated: 2023/09/17 23:29:47 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TokenizerBase.hpp"

#include <string>

TokenizerBase::TokenizerBase()
  : string_(std::string()),
    pos_(0),
    is_valid_(false) {}

TokenizerBase::TokenizerBase(std::string string)
  : string_(string),
    pos_(0),
    is_valid_(false) {}

TokenizerBase::TokenizerBase(const TokenizerBase& value)
  : string_(value.string_),
    pos_(value.pos_),
    is_valid_(value.is_valid_) {}

TokenizerBase::~TokenizerBase() {}

const TokenizerBase& TokenizerBase::operator=(const TokenizerBase& value)
{
  if (this == &value)
    return *this;
  string_ = value.string_;
  pos_ = value.pos_;
  is_valid_ = value.is_valid_;
  return *this;
}

bool  TokenizerBase::is_valid() const
{
  return is_valid_;
}

bool  TokenizerBase::is_end() const
{
  return pos_ == string_.size();
}

void  TokenizerBase::set_string(std::string string)
{
  string_ = string;
  pos_ = 0;
  is_valid_ = false;
}
