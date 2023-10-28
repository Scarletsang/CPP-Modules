/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:16:33 by htsang            #+#    #+#             */
/*   Updated: 2023/10/28 17:11:53 by htsang           ###   ########.fr       */
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
#include "parser.hpp"

template <>
std::ostream& operator<<(std::ostream& os, Result<char, converter::Error> const& result)
{
  if (result.is_ok())
    os << "'" << result.value() << "'";
  else
  {
    switch (result.error())
    {
      case converter::kNonDisplayableError:
        os << "Non displayable";
        break;
      case converter::kNanError:
      case converter::kPositiveInfinityError:
      case converter::kNegativeInfinityError:
      case converter::kImpossibleError:
        os << "impossible";
        break;
      default:
        break;
    }
  }
  return os;
}

template <>
std::ostream& operator<<(std::ostream& os, Result<int, converter::Error> const& result)
{
  if (result.is_ok())
    os << result.value();
  else
  {
    switch (result.error())
    {
      case converter::kNonDisplayableError:
        os << "Non displayable";
        break;
      case converter::kNanError:
      case converter::kPositiveInfinityError:
      case converter::kNegativeInfinityError:
      case converter::kImpossibleError:
        os << "impossible";
        break;
      default:
        break;
    }
  }
  return os;
}

template <>
std::ostream& operator<<(std::ostream& os, Result<float, converter::Error> const& result)
{
  if (result.is_ok())
    os << result.value();
  else
  {
    switch (result.error())
    {
      case converter::kNonDisplayableError:
        os << "Non displayable";
        break;
      case converter::kImpossibleError:
        os << "impossible";
        break;
      case converter::kNanError:
        os << "nanf";
        break;
      case converter::kPositiveInfinityError:
        os << "+inff";
        break;
      case converter::kNegativeInfinityError:
        os << "-inff";
        break;
      default:
        break;
    }
  }
  return os;
}

template <>
std::ostream& operator<<(std::ostream& os, Result<double, converter::Error> const& result)
{
  if (result.is_ok())
    os << result.value();
  else
  {
    switch (result.error())
    {
      case converter::kNonDisplayableError:
        os << "Non displayable";
        break;
      case converter::kImpossibleError:
        os << "impossible";
        break;
      case converter::kNanError:
        os << "nan";
        break;
      case converter::kPositiveInfinityError:
        os << "+inf";
        break;
      case converter::kNegativeInfinityError:
        os << "-inf";
        break;
      default:
        break;
    }
  }
  return os;
}

template <typename T>
static void Print(converter::Scalar<T> scalar)
{
  std::cout << "char: " << scalar.to_char() << std::endl;
  std::cout << "int: " << scalar.to_int() << std::endl;
  std::cout << "float: " << scalar.to_float() << std::endl;
  std::cout << "double: " << scalar.to_double() << std::endl;
}

void  ScalarConverter::convert(std::string const& str)
{
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
