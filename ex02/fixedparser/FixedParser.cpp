/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedParser.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:36:43 by htsang            #+#    #+#             */
/*   Updated: 2023/09/18 00:32:24 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FixedParser.hpp"
#include "FixedToken.hpp"
#include "Fixed.hpp"

#include <iostream>

FixedParser::FixedParser(const FixedParser& value) : Parser(value) {}

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
  // convert string to Fixed point number
  // return Fixed point number
  
}

Fixed FixedParser::parse_factor()
{
  if (tokenize())
    return parse_error(0);
  FixedToken *token = stack_.peek();
  if (token->type == FixedToken::kOpenParenthesis)
  {
    stack_.pop();
    Fixed result = parse_expression();
    if (tokenize() || stack_.peek()->type != FixedToken::kCloseParenthesis)
      return parse_error(0);
    stack_.pop();
    return result;
  }
  else if (token->type == FixedToken::kNumber)
    return process_number(token);
  else
    return parse_error(0);
}
