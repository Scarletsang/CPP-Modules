/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 03:22:27 by htsang            #+#    #+#             */
/*   Updated: 2023/10/28 05:15:30 by htsang           ###   ########.fr       */
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

  Parser::Parser(std::string const string) : str(string), it(str.begin()) {}

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

  bool  Sign(struct Parser &parser, bool &positive)
  {
    positive = true;
    if (Character(parser, '+')) return true;
    else if (Character(parser, '-'))
    {
      positive = false;
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
    bool          is_positive = true;
    int           i = 0;
    struct Parser parser(str);

    Sign(parser, is_positive);
    IntResult result = Number<int>(parser, i, is_positive);
    if (!parser.is_end())
      return IntResult::Error(kIncorrectTypeError);
    else
      return result;
  }

  // TODO: Incomplete
  FloatResult Float(std::string const& str)
  {
    if (str == "nanf") return ParseResultType<float>(convert::Type::Nan());
    else if (str == "+inff") return ParseResultType<float>(convert::Type::PositiveInfinity());
    else if (str == "-inff") return ParseResultType<float>(convert::Type::NegativeInfinity());
    bool          is_positive = true;
    float         i = 0;
    struct Parser parser(str);

    Sign(parser, is_positive);
    FloatResult result = Number<float>(parser, i, is_positive);
    if (!result.is_ok() || !Character(parser, '.'))
      return FloatResult::Error(kIncorrectTypeError);
    result = Decimals<float>(parser, i, is_positive);
    if (!Character(parser, 'f') || !parser.is_end())
      return FloatResult::Error(kIncorrectTypeError);
    else
      return result;
  }

  // TODO: Incomplete
  DoubleResult Double(std::string const& str)
  {
    if (str == "nan") return ParseResultType<double>(convert::Type::Nan());
    else if (str == "+inf") return ParseResultType<double>(convert::Type::PositiveInfinity());
    else if (str == "-inf") return ParseResultType<double>(convert::Type::NegativeInfinity());
    bool          is_positive = true;
    double        i = 0;
    struct Parser parser(str);

    Sign(parser, is_positive);
    DoubleResult result = Number<double>(parser, i, is_positive);
    if (!result.is_ok() || !Character(parser, '.'))
      return DoubleResult::Error(kIncorrectTypeError);
    result = Decimals<double>(parser, i, is_positive);
    if (!parser.is_end())
      return DoubleResult::Error(kIncorrectTypeError);
    else
      return result;
  }
  
} // namespace parser
