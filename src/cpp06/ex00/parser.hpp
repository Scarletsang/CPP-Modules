/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 03:25:19 by htsang            #+#    #+#             */
/*   Updated: 2023/10/28 17:11:53 by htsang           ###   ########.fr       */
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

  typedef Result<converter::Scalar<char>, parser::Error>   CharResult;
  typedef Result<converter::Scalar<int>, parser::Error>    IntResult;
  typedef Result<converter::Scalar<float>, parser::Error>  FloatResult;
  typedef Result<converter::Scalar<double>, parser::Error> DoubleResult;

  template <typename T>
  Result<converter::Scalar<T>, parser::Error> ParseResult(T value);

  template <typename T>
  Result<converter::Scalar<T>, parser::Error> ParseResultType(converter::ScalarType type);

  template <typename T>
  Result<converter::Scalar<T>, parser::Error> ParseResultError(parser::Error error);

  struct Parser
  {
    const std::string           str;
    std::string::const_iterator it;
    bool                        is_positive;
    Parser(std::string const str);

    bool  is_end() const;
    bool  has_next() const;
  };

  bool  Character(struct Parser &parser, char c);

  bool  Sign(struct Parser &parser);

  template <typename T>
  Result<converter::Scalar<T>, parser::Error> Number(\
    struct Parser &parser, 
    T &i);

  template <typename T>
  Result<converter::Scalar<T>, parser::Error> Decimals(\
    struct Parser &parser, 
    T &i);

  CharResult  Char(std::string const& str);

  IntResult   Int(std::string const& str);

  FloatResult Float(std::string const& str);

  DoubleResult  Double(std::string const& str);

  //////////////////////////////////////////////////////
  ////////////   templates implementation   ////////////
  //////////////////////////////////////////////////////

  template <typename T>
  Result<converter::Scalar<T>, parser::Error> ParseResult(T value)
  {
    return (Result<converter::Scalar<T>, parser::Error>::Ok(converter::Scalar<T>(value)));
  }

  template <typename T>
  Result<converter::Scalar<T>, parser::Error> ParseResultType(converter::ScalarType type)
  {
    return (Result<converter::Scalar<T>, parser::Error>::Ok(converter::Scalar<T>(type)));
  }

  template <typename T>
  Result<converter::Scalar<T>, parser::Error> ParseResultError(parser::Error error)
  {
    return (Result<converter::Scalar<T>, parser::Error>::Error(error));
  }

  template <typename T>
  Result<converter::Scalar<T>, parser::Error> Number(struct Parser &parser, T &i)
  {
    std::string::const_iterator str_start = parser.it;
    if (parser.is_positive)
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
        else if (i < ((converter::MinimumValue<T>() + (*parser.it - '0')) / 10))
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
  Result<converter::Scalar<T>, parser::Error> Decimals(struct Parser &parser, T &i)
  {
    std::string::const_iterator str_start = parser.it;
    if (parser.is_positive)
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
        else if (i < (converter::MinimumValue<T>() + ((*parser.it - '0') / 10)))
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
