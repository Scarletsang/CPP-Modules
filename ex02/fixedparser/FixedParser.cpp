/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedParser.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:36:43 by htsang            #+#    #+#             */
/*   Updated: 2023/09/18 15:48:01 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixedparser/FixedParser.hpp"
#include "fixedparser/FixedToken.hpp"
#include "Fixed.hpp"

#include <iostream>

FixedParser::FixedParser(const FixedParser& value) : Parser(value) {}

FixedParser::FixedParser(Tokenizer<FixedToken> &tokenizer)
  : Parser(tokenizer) {}

FixedParser::~FixedParser() {}

const FixedParser& FixedParser::operator=(const FixedParser& value)
{
  Parser::operator=(value);
  return *this;
}

void  FixedParser::handle_error(int error_code)
{
  (void)error_code;
  if (has_malloc_error())
    std::cerr << "malloc error" << std::endl;
  else if (has_tokenizer_error())
    std::cerr << "tokenizer error" << std::endl;
  else if (has_syntax_error())
    std::cerr << "syntax error" << std::endl;
}

Fixed FixedParser::process_number(FixedToken *token)
{
  float                 number;
  std::string::iterator it = token->value.begin();

  number = 0;
  while ((it != token->value.end()) && std::isdigit(*it))
  {
    number = number * 10 + (*it - '0');
    it++;
  }
  if ((it != token->value.end()) && (*it == '.'))
  {
    it++;
    float factor = 1;
    while ((it != token->value.end()) && std::isdigit(*it))
    {
      factor /= 10;
      number += (*it - '0') * factor;
      it++;
    }
  }
  if (it != token->value.end())
    return parse_error(0);
  return Fixed(number);
}

Fixed FixedParser::parse_factor()
{
  if (tokenize())
    return parse_error(0);
  FixedToken *token = stack_.peek();
  if (token->type == FixedToken::kOpenParenthesis)
  {
    delete stack_.pop();
    Fixed result = parse_expression();
    if (tokenize() || stack_.peek()->type != FixedToken::kCloseParenthesis)
      return parse_error(0);
    delete stack_.pop();
    return result;
  }
  else if (token->type == FixedToken::kMinus)
  {
    delete stack_.pop();
    if (tokenize() || stack_.peek()->type != FixedToken::kNumber)
      return parse_error(0);
    Fixed result = process_number(stack_.peek()) * -1;
    delete stack_.pop();
    return result;
  }
  else if (token->type == FixedToken::kNumber)
    return process_number(token);
  else
    return parse_error(0);
}

Fixed FixedParser::parse_term()
{
  Fixed result = parse_factor();
  if (is_end())
    return result;
  else if (tokenize())
    return parse_error(0);
  while (!stack_.is_empty() && (stack_.peek()->type == FixedToken::kMultiply ||
                                stack_.peek()->type == FixedToken::kDivide))
  {
    FixedToken *token = stack_.pop();
    Fixed right = parse_factor();
    if (token->type == FixedToken::kMultiply)
      result = result * right;
    else
      result = result / right;
    delete token;
  }
  return result;
}

Fixed FixedParser::parse_expression()
{
  Fixed result = parse_term();
  if (is_end())
    return result;
  else if (tokenize())
    return parse_error(0);
  std::cerr << "right: " << stack_.peek()->value << std::endl;
  while (!stack_.is_empty() && (stack_.peek()->type == FixedToken::kPlus ||
                                stack_.peek()->type == FixedToken::kMinus))
  {
    FixedToken *token = stack_.pop();
    Fixed right = parse_factor();
    if (token->type == FixedToken::kPlus)
      result = result + right;
    else
      result = result - right;
    delete token;
  }
  return result;
}

Fixed FixedParser::parse()
{
  return parse_expression();
}
