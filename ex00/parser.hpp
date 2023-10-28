/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 03:25:19 by htsang            #+#    #+#             */
/*   Updated: 2023/10/28 05:11:20 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#include "Result.hpp"
#include "Scalar.hpp"

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
  Result<convert::Scalar<T>, parser::Error> ParseResult(T value);

  template <typename T>
  Result<convert::Scalar<T>, parser::Error> ParseResultType(convert::Type type);

  template <typename T>
  Result<convert::Scalar<T>, parser::Error> ParseResultError(parser::Error error);

  struct Parser
  {
    const std::string           str;
    std::string::const_iterator it;
    Parser(std::string const str);

    bool  is_end() const;
    bool  has_next() const;
  };

  bool  Character(struct Parser &parser, char c);

  bool  Sign(struct Parser &parser, bool &positive);

  template <typename T>
  Result<convert::Scalar<T>, parser::Error> Number(\
    struct Parser &parser, 
    T &i,
    bool is_positive);

  template <typename T>
  Result<convert::Scalar<T>, parser::Error> Decimals(\
    struct Parser &parser, 
    T &i,
    bool is_positive);

  CharResult  Char(std::string const& str);

  IntResult   Int(std::string const& str);

  FloatResult Float(std::string const& str);

  DoubleResult  Double(std::string const& str);

  //////////////////////////////////////////////////////
  ////////////   templates implementation   ////////////
  //////////////////////////////////////////////////////

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

  template <typename T>
  Result<convert::Scalar<T>, parser::Error> Number(\
    struct Parser &parser, 
    T &i,
    bool is_positive)
  {
    std::string::const_iterator str_start = parser.it;
    if (is_positive)
    {
      for (; !parser.is_end(); ++parser.it)
      {
        if (*parser.it < '0' || *parser.it > '9')
          break;
        else if (i > ((std::numeric_limits<T>::max() - (*parser.it - '0')) / 10))
          return ParseResultError<T>(kIncorrectTypeError);
        i = i * 10 + (*parser.it - '0');
      }
    }
    else
    { 
      for (; !parser.is_end(); ++parser.it)
      {
        if (*parser.it < '0' || *parser.it > '9')
          break;
        else if (i > ((std::numeric_limits<T>::min() + (*parser.it - '0')) / 10))
          return ParseResultError<T>(kIncorrectTypeError);
        i = i * 10 - (*parser.it - '0');
      }
    }
    if (parser.it == str_start)
      return ParseResultError<T>(kIncorrectTypeError);
    else
      return ParseResult<T>(i);
  }

  template <typename T>
  Result<convert::Scalar<T>, parser::Error> Decimals(\
    struct Parser &parser, 
    T &i,
    bool is_positive)
  {
    std::string::const_iterator str_start = parser.it;
    if (is_positive)
    {
      for (T n = 10; !parser.is_end(); ++parser.it)
      {
        if (*parser.it < '0' || *parser.it > '9')
          break;
        else if (i > (std::numeric_limits<T>::max() - ((*parser.it - '0') / 10)))
          return ParseResultError<T>(kIncorrectTypeError);
        i = i + (*parser.it - '0') / n;
        n *= 10;
      }
    }
    else
    { 
      for (T n = 10; !parser.is_end(); ++parser.it)
      {
        if (*parser.it < '0' || *parser.it > '9')
          break;
        else if (i > (std::numeric_limits<T>::min() + ((*parser.it - '0') / 10)))
          return ParseResultError<T>(kIncorrectTypeError);
        i = i - (*parser.it - '0') / n;
        n *= 10;
      }
    }
    if (parser.it == str_start)
      return ParseResultError<T>(kIncorrectTypeError);
    else
      return ParseResult<T>(i);
  }
  
} // namespace parser
