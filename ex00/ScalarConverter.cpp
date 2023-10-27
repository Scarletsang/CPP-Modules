/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:16:33 by htsang            #+#    #+#             */
/*   Updated: 2023/10/28 01:16:33 by htsang           ###   ########.fr       */
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

  typedef Result<convert::Scalar<char>, parser::Error>   CharResult;
  typedef Result<convert::Scalar<int>, parser::Error>    IntResult;
  typedef Result<convert::Scalar<float>, parser::Error>  FloatResult;
  typedef Result<convert::Scalar<double>, parser::Error> DoubleResult;

  template <typename T>
  Result<convert::Scalar<T>, parser::Error> ParseResult(T value)
  {
    return (Result<convert::Scalar<T>, parser::Error>::Ok(convert::Scalar<T>(value)));
  }

  template <typename T>
  Result<convert::Scalar<T>, parser::Error> ParseResultType(convert::Type type)
  {
    return (Result<convert::Scalar<T>, parser::Error>::Ok(convert::Scalar<T>(type)));
  }

  template <typename T>
  Result<convert::Scalar<T>, parser::Error> ParseResultError(parser::Error error)
  {
    return (Result<convert::Scalar<T>, parser::Error>::Error(error));
  }

  static bool  IsEmpty(std::string const& str)
  {
    return (str.length() == 0);
  }

  static bool Character(std::string::const_iterator &it, char c)
  {
    if (*it == c)
    {
      ++it;
      return (true);
    }
    return (false);
  }

  static bool  Sign(std::string::const_iterator &it, bool &positive)
  {
    positive = true;
    if (Character(it, '+')) return (true);
    else if (Character(it, '-'))
    {
      positive = false;
      return (true);
    }
    return (false);
  }

  template <typename T>
  static Result<convert::Scalar<T>, parser::Error> Number(std::string::const_iterator &it, T &i, bool is_positive)
  {
    if (is_positive)
    {
      for (; it != str.end(); ++it)
      {
        if (*it < '0' || *it > '9')
          return ParseResultError<T>(kIncorrectTypeError);
        else if (i > (std::numeric_limits<int>::max() / 10) - (*it - '0'))
          return ParseResultError<T>(kIncorrectTypeError);
        i = i * 10 + (*it - '0');
      }
    }
    else
    { 
      for (; it != str.end(); ++it)
      {
        if (*it < '0' || *it > '9')
          return ParseResultError<T>(kIncorrectTypeError);
        else if (i < (std::numeric_limits<int>::min() / 10) + (*it - '0'))
          return ParseResultError<T>(kIncorrectTypeError);
        i = i * 10 - (*it - '0');
      }
    }
    return ParseResult<T>(i);
  }

  static CharResult  Char(std::string const& str)
  {
    if (str.length() == 1 && std::isprint(str[0]))
      return ParseResult<char>(str[0]);
    else
      return CharResult::Error(kTooManyCharactersError);
  }

  // sign
  // numbers
  // . => float or double
  // numbers
  // f => float

  static IntResult Int(std::string const& str)
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
        return IntResult::Error(kIncorrectTypeError);
      // check overflow and underflow
      if (i > std::numeric_limits<int>::max() / 10)
        return IntResult::Error(kIncorrectTypeError);
      else if (i < std::numeric_limits<int>::min() / 10)
        return IntResult::Error(kIncorrectTypeError);
      i = i * 10 + (*it - '0');
    }
    return ParseResult<int>(i * sign);
  }

  // TODO: Incomplete
  static FloatResult Float(std::string const& str)
  {
    if (str == "nanf") return (ParseResultType<float>(convert::Type::Nan()));
    else if (str == "+inff") return (ParseResultType<float>(convert::Type::PositiveInfinity()));
    else if (str == "-inff") return (ParseResultType<float>(convert::Type::NegativeInfinity()));
    // double d = std::strtof(str.c_str(), NULL);

    // if (d == HUGE_VAL) ;
    return (FloatResult::Error(kIncorrectTypeError));
  }

  // TODO: Incomplete
  static DoubleResult Double(std::string const& str)
  {
    if (str == "nan") return (ParseResultType<double>(convert::Type::Nan()));
    else if (str == "+inf") return (ParseResultType<double>(convert::Type::PositiveInfinity()));
    else if (str == "-inf") return (ParseResultType<double>(convert::Type::NegativeInfinity()));
    double d = std::strtod(str.c_str(), NULL);

    return (ParseResult<double>(d));
  }
  
} // namespace parser

template <>
std::ostream& operator<<(std::ostream& os, Result<char, convert::Error> const& result)
{
  if (result.is_ok())
    os << "'" << result.value() << "'";
  else
  {
    switch (result.error())
    {
      case convert::kNonDisplayableError:
        os << "Non displayable";
        break;
      case convert::kNanError:
      case convert::kPositiveInfinityError:
      case convert::kNegativeInfinityError:
      case convert::kImpossibleError:
        os << "impossible";
        break;
      default:
        break;
    }
  }
  return os;
}

template <>
std::ostream& operator<<(std::ostream& os, Result<int, convert::Error> const& result)
{
  if (result.is_ok())
    os << result.value();
  else
  {
    switch (result.error())
    {
      case convert::kNonDisplayableError:
        os << "Non displayable";
        break;
      case convert::kNanError:
      case convert::kPositiveInfinityError:
      case convert::kNegativeInfinityError:
      case convert::kImpossibleError:
        os << "impossible";
        break;
      default:
        break;
    }
  }
  return os;
}

template <>
std::ostream& operator<<(std::ostream& os, Result<float, convert::Error> const& result)
{
  if (result.is_ok())
    os << result.value();
  else
  {
    switch (result.error())
    {
      case convert::kNonDisplayableError:
        os << "Non displayable";
        break;
      case convert::kImpossibleError:
        os << "impossible";
        break;
      case convert::kNanError:
        os << "nanf";
        break;
      case convert::kPositiveInfinityError:
        os << "+inff";
        break;
      case convert::kNegativeInfinityError:
        os << "-inff";
        break;
      default:
        break;
    }
  }
  return os;
}

template <>
std::ostream& operator<<(std::ostream& os, Result<double, convert::Error> const& result)
{
  if (result.is_ok())
    os << result.value();
  else
  {
    switch (result.error())
    {
      case convert::kNonDisplayableError:
        os << "Non displayable";
        break;
      case convert::kImpossibleError:
        os << "impossible";
        break;
      case convert::kNanError:
        os << "nan";
        break;
      case convert::kPositiveInfinityError:
        os << "+inf";
        break;
      case convert::kNegativeInfinityError:
        os << "-inf";
        break;
      default:
        break;
    }
  }
  return os;
}

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
  parser::FloatResult  float_result = parser::Float(str);
  if (float_result.is_ok())
  {
    std::cout << "Type Detection: float" << std::endl;
    Print(float_result.value());
    return ;
  }
  parser::DoubleResult double_result = parser::Double(str);
  if (double_result.is_ok())
  {
    std::cout << "Type Detection: double" << std::endl;
    Print(double_result.value());
    return ;
  }
  parser::IntResult    int_result = parser::Int(str);
  if (int_result.is_ok())
  {
    std::cout << "Type Detection: int" << std::endl;
    Print(int_result.value());
    return ;
  }
  parser::CharResult   char_result = parser::Char(str);
  if (char_result.is_ok())
  {
    std::cout << "Type Detection: char" << std::endl;
    Print(char_result.value());
    return ;
  }
  std::cout << "Type Detection: impossible" << std::endl;
}
