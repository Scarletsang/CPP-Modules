/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:16:33 by htsang            #+#    #+#             */
/*   Updated: 2023/10/12 19:27:22 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cstdlib>
#include <cmath>

#include <iostream>
#include <string>
#include <stdexcept>

#include "ScalarType.hpp"
#include "Result.hpp"

namespace parser
{
  enum  Error
  {
    kEmptyStringError,
    kTooManyCharactersError,
    kIncorrectTypeError
  };

  static  bool  IsEmpty(std::string const& str)
  {
    return (str.length() == 0);
  }

  static Result<char, enum Error>  Char(std::string const& str)
  {
    if (str.length() == 1)
      return (Result<char, enum Error>(str[0]));
    else if (str.length() == 2 && str[0] == '\'')
      return (Result<char, enum Error>(str[1]));
    else
      return (Result<char, enum Error>(kTooManyCharactersError));
  }

  // TODO: Incomplete
  static Result<int, enum Error> Int(std::string const& str)
  {
    int i = atoi(str.c_str());
    if (i == 0 && str[0] == '0' && str.length() > 1)
      return (Result<int, enum Error>(kNanError));
    else
      return (Result<int, enum Error>(i));
  }

  // TODO: Incomplete
  static Result<float, enum Error> Float(std::string const& str)
  {
    float f = std::strtod(str.c_str(), NULL);
  
    if (f == HUGE_VAL) ;
  }

  // TODO: Incomplete
  static Result<double, enum Error> Double(std::string const& str)
  {
    double d = std::strtod(str.c_str(), NULL);
  }
  
} // namespace parser

template <typename T>
static void Print(ScalarType<T> scalar)
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
  Result<float, enum parser::Error>  float_result = parser::Float(str);
  if (float_result.is_ok())
  {
    Print(ScalarType<float>(float_result.value()));
    return ;
  }
  Result<double, enum parser::Error> double_result = parser::Double(str);
  if (double_result.is_ok())
  {
    Print(ScalarType<double>(double_result.value()));
    return ;
  }
  Result<int, enum parser::Error>    int_result = parser::Int(str);
  if (int_result.is_ok())
  {
    Print(ScalarType<int>(int_result.value()));
    return ;
  }
  Result<char, enum parser::Error>   char_result = parser::Char(str);
  if (char_result.is_ok())
  {
    Print(ScalarType<char>(char_result.value()));
    return ;
  }
}
