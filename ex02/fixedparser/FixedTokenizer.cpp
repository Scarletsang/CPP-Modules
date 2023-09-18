/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedTokenizer.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:23:50 by htsang            #+#    #+#             */
/*   Updated: 2023/09/17 23:45:31 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FixedTokenizer.hpp"
#include "FixedToken.hpp"

FixedTokenizer::FixedTokenizer() : Tokenizer() {}

FixedTokenizer::FixedTokenizer(const FixedTokenizer& value)
  : Tokenizer(value) {}

FixedTokenizer::~FixedTokenizer() {}

const FixedTokenizer& FixedTokenizer::operator=(const FixedTokenizer& value)
{
  Tokenizer::operator=(value);
  return *this;
}  

FixedToken* FixedTokenizer::tokenize_number()
{
  size_t  end = pos_;
  FixedToken   *token;

  while ((end < string_.size()) && std::isdigit(string_[end]))
    end++;
  if ((end < string_.size()) && (string_[end] == '.'))
  {
    end++;
    while (((end < string_.size())) && std::isdigit(string_[end]))
      end++;
  }
  token = new FixedToken(FixedToken::kNumber, string_.substr(pos_, end - pos_));
  pos_ = end;
  return token;
}

FixedToken* FixedTokenizer::tokenize_one(FixedToken::Type type)
{
  FixedToken *token = new FixedToken(type, string_.substr(pos_, 1));
  pos_++;
  return token;
}

FixedToken* FixedTokenizer::next()
{
  if (tokens_.size() > 0)
    return tokens_.pop();
  else if (is_end())
    return NULL;
  else if (std::isdigit(string_[pos_]))
    return tokenize_number();
  else if (string_[pos_] == '+')
    return tokenize_one(FixedToken::kPlus);
  else if (string_[pos_] == '-')
    return tokenize_one(FixedToken::kMinus);
  else if (string_[pos_] == '*')
    return tokenize_one(FixedToken::kMultiply);
  else if (string_[pos_] == '/')
    return tokenize_one(FixedToken::kDivide);
  else if (string_[pos_] == '(')
    return tokenize_one(FixedToken::kOpenParenthesis);
  else if (string_[pos_] == ')')
    return tokenize_one(FixedToken::kCloseParenthesis);
  else if (string_[pos_] == ' ')
  {
    pos_++;
    return next();
  }
  else
  {
    is_valid_ = false;
    return NULL;
  }
}
