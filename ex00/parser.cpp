/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 03:22:27 by htsang            #+#    #+#             */
/*   Updated: 2023/10/28 17:12:55 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.hpp"

#include <cstdlib>
#include <cmath>

#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>

#include "Result.hpp"
#include "Scalar.hpp"

namespace parser
{
  Parser::Parser(std::string const string)
    : str(string),
      it(str.begin()),
      is_positive(true) {}

  bool  Parser::is_end() const
  {
    return (it == str.end());
  }

  bool  Parser::has_next() const
  {
    return ((it + 1) != str.end());
  }

  bool Character(struct Parser &parser, char c)
  {
    if (!parser.is_end() && (*parser.it == c))
    {
      ++parser.it;
      return true;
    }
    return false;
  }

  bool  Sign(struct Parser &parser)
  {
    parser.is_positive = true;
    if (Character(parser, '+')) return true;
    else if (Character(parser, '-'))
    {
      parser.is_positive = false;
      return true;
    }
    return false;
  }

  CharResult  Char(std::string const& str)
  {
    if (str.length() == 1 && std::isprint(str[0]))
      return ParseResult<char>(str[0]);
    else
      return CharResult::Error(kTooManyCharactersError);
  }

  IntResult Int(std::string const& str)
  {
    int           i = 0;
    struct Parser parser(str);

    Sign(parser);
    IntResult result = Number<int>(parser, i);
    if (!parser.is_end())
      return IntResult::Error(kIncorrectTypeError);
    else
      return result;
  }

  FloatResult Float(std::string const& str)
  {
    if (str == "nanf") return ParseResultType<float>(converter::ScalarType::Nan());
    else if (str == "+inff") return ParseResultType<float>(converter::ScalarType::PositiveInfinity());
    else if (str == "-inff") return ParseResultType<float>(converter::ScalarType::NegativeInfinity());
    float         i = 0;
    struct Parser parser(str);

    Sign(parser);
    FloatResult result = Number<float>(parser, i);
    if (!result.is_ok() || !Character(parser, '.'))
      return FloatResult::Error(kIncorrectTypeError);
    result = Decimals<float>(parser, i);
    if (!Character(parser, 'f') || !parser.is_end())
      return FloatResult::Error(kIncorrectTypeError);
    else
      return result;
  }

  DoubleResult Double(std::string const& str)
  {
    if (str == "nan") return ParseResultType<double>(converter::ScalarType::Nan());
    else if (str == "+inf") return ParseResultType<double>(converter::ScalarType::PositiveInfinity());
    else if (str == "-inf") return ParseResultType<double>(converter::ScalarType::NegativeInfinity());
    double        i = 0;
    struct Parser parser(str);

    Sign(parser);
    DoubleResult result = Number<double>(parser, i);
    if (!result.is_ok() || !Character(parser, '.'))
      return DoubleResult::Error(kIncorrectTypeError);
    result = Decimals<double>(parser, i);
    if (!parser.is_end())
      return DoubleResult::Error(kIncorrectTypeError);
    else
      return result;
  }
} // namespace parser
