/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:16:33 by htsang            #+#    #+#             */
/*   Updated: 2023/10/20 23:05:54 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cstdlib>
#include <cmath>

#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>

#include "Scalar.hpp"
#include "Result.hpp"

namespace parser
{
  enum  Error
  {
    kEmptyStringError,
    kTooManyCharactersError,
    kIncorrectTypeError
  };

  static bool  IsEmpty(std::string const& str)
  {
    return (str.length() == 0);
  }

  static Result<char, parser::Error>  Char(std::string const& str)
  {
    if (str.length() == 1 && std::isprint(str[0]))
      return (Result<char, parser::Error>(str[0]));
    else
      return (Result<char, parser::Error>(kTooManyCharactersError));
  }

  // sign
  // numbers
  // . => float or double
  // numbers
  // f => float

  static Result<int, parser::Error> Int(std::string const& str)
  {
    int i = 0;
    int sign = 1;
    std::string::const_iterator it = str.begin();

    if (*it == '+')
    {
      ++it;
    }
    else if (*it == '-')
    {
      sign = -1;
      ++it;
    }
    for (; it != str.end(); ++it)
    {
      if (*it < '0' || *it > '9')
        return (Result<int, parser::Error>(kIncorrectTypeError));
      // check overflow and underflow
      if (i > std::numeric_limits<int>::max() / 10)
        return (Result<int, parser::Error>(kIncorrectTypeError));
      else if (i < std::numeric_limits<int>::min() / 10)
        return (Result<int, parser::Error>(kIncorrectTypeError));
      i = i * 10 + (*it - '0');
    }
    return (Result<int, parser::Error>(i * sign));
  }

  // TODO: Incomplete
  static Result<float, parser::Error> Float(std::string const& str)
  {
    double d = std::strtof(str.c_str(), NULL);

    // if (d == HUGE_VAL) ;
    return (Result<float, parser::Error>(d));
  }

  // TODO: Incomplete
  static Result<double, parser::Error> Double(std::string const& str)
  {
    double d = std::strtod(str.c_str(), NULL);

    return (Result<double, parser::Error>(d));
  }
  
} // namespace parser

template <typename T>
static void Print(convert::Scalar<T> scalar)
{
  std::cout << "char: " << scalar.to_char() << std::endl;
  std::cout << "int: " << scalar.to_int() << std::endl;
  std::cout << "float: " << scalar.to_float() << std::endl;
  std::cout << "double: " << scalar.to_double() << std::endl;
}

void  ScalarConverter::convert(std::string const& str)
{
  if (parser::IsEmpty(str))
  {
    std::cout << "Usage: ./convert [string]" << std::endl;
    return ;
  }
  Result<float, parser::Error>  float_result = parser::Float(str);
  if (float_result.is_ok())
  {
    Print(convert::Scalar<float>(float_result.value()));
    return ;
  }
  Result<double, parser::Error> double_result = parser::Double(str);
  if (double_result.is_ok())
  {
    Print(convert::Scalar<double>(double_result.value()));
    return ;
  }
  Result<int, parser::Error>    int_result = parser::Int(str);
  if (int_result.is_ok())
  {
    Print(convert::Scalar<int>(int_result.value()));
    return ;
  }
  Result<char, parser::Error>   char_result = parser::Char(str);
  if (char_result.is_ok())
  {
    Print(convert::Scalar<char>(char_result.value()));
    return ;
  }
}
