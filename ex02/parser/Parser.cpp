/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:30:06 by htsang            #+#    #+#             */
/*   Updated: 2023/09/14 15:25:35 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

#include <string>

namespace parser
{
  Result<Nothing>  Ignore(std::string input, char c)
  {
    Result<Nothing> result(input);
  
    result.set_valid(result.string()[0] == c);
    if (result.is_valid())
      result.advance(1);
    return result;
  }

  Result<Nothing>  Ignore(std::string input, std::string string)
  {
    Result<Nothing> result(input);
  
    result.set_valid(result.string().find(string) == 0);
    if (result.is_valid())
      result.advance(string.size());
    return result;
  }

  Result<Nothing>  IgnoreOneOf(std::string input, std::string set)
  {
    Result<Nothing> result(input);
  
    result.set_valid(set.find(result.string()[0]) != std::string::npos);
    if (result.is_valid())
      result.advance(1);
    return result;
  }

  Result<bool>  Expect(std::string input, char c)
  {
    Result<bool> result(input);
  
    result.set_valid(result.string()[0] == c);
    if (result.is_valid())
      result.set_value(true);
    return result;
  }

  Result<bool>  Expect(std::string input, std::string string)
  {
    Result<bool> result(input);
  
    result.set_valid(result.string().find(string) == 0);
    if (result.is_valid())
      result.set_value(true);
    return result;
  }

  Result<bool>  ExpectOneOf(std::string input, std::string set)
  {
    Result<bool> result(input);
  
    result.set_valid(set.find(result.string()[0]) != std::string::npos);
    if (result.is_valid())
      result.set_value(true);
    return result;
  }

  Result<bool>  Match(std::string input, char c)
  {
    Result<bool> result(input);
  
    result.set_valid(result.string()[0] == c);
    result.set_value(result.is_valid());
    if (result.is_valid())
      result.advance(1);
    return result;
  }

  Result<bool>  Match(std::string input, std::string string)
  {
    Result<bool> result(input);
  
    result.set_valid(result.string().find(string) == 0);
    result.set_value(result.is_valid());
    if (result.is_valid())
      result.advance(string.size());
    return result;
  }

  Result<bool>  MatchOneOf(std::string input, std::string set)
  {
    Result<bool> result(input);
  
    result.set_valid(set.find(result.string()[0]) != std::string::npos);
    result.set_value(result.is_valid());
    if (result.is_valid())
      result.advance(1);
    return result;
  }

  Result<char>  Char(std::string input)
  {
    Result<char> result(input);
  
    result.set_valid(result.string().size() > 0);
    if (result.is_valid())
    {
      result.set_value(result.string()[0]);
      result.advance(1);
    }
    return result;
  }

  Result<char>  CharOf(std::string input, std::string set)
  {
    Result<char> result(input);
  
    result.set_valid(set.find(result.string()[0]) != std::string::npos);
    if (result.is_valid())
    {
      result.set_value(result.string()[0]);
      result.advance(1);
    }
    return result;
  }

  Result<std::string>  String(std::string input, std::string delimiter)
  {
    Result<std::string> result(input);
  
    result.set_valid(result.string().find(delimiter) == 0);
    if (result.is_valid())
    {
      result.set_value(result.string().substr(0, delimiter.size()));
      result.advance(delimiter.size());
    }
    return result;
  }

  Result<int>   Integer(std::string input)
  {
    Result<int> result(input);
    int         sign = 1;
  
    result.chain(Ignore(input, '-'));
    result.is_valid() ? sign = -1 : sign = 1;
    if (!std::isdigit(result.string()[0]))
    {
      result.set_valid(false);
      return result;
    }
    result.set_valid(true);
    int value = 0;
    for (std::string::iterator it = result.string().begin();
        (it != result.string().end()) && std::isdigit(*it); it++)
    {
      value = value * 10 + (*it - '0');
    }
    result.set_value(value * sign);
    return result;
  }

  Result<float> Float(std::string input)
  {
    Result<float> result(input);
    float         sign = 1;
  
    result.chain(Ignore(input, '-'));
    result.is_valid() ? sign = -1 : sign = 1;
    if (!std::isdigit(result.string()[0]))
    {
      result.set_value(0);
      result.set_valid(false);
      return result;
    }
    float value = 0;
    for (std::string::iterator it = result.string().begin();
        (it != result.string().end()) && std::isdigit(*it); it++)
    {
      value = value * 10 + (*it - '0');
    }
    if (result.chain(Match(result.string(), '.')))
    {
      float decimal = 0.f;
      float power   = 10.0f;
  
      for (std::string::iterator it = result.string().begin();
          (it != result.string().end()) && std::isdigit(*it); it++)
      {
        decimal += ((*it - '0') / power);
        power *= 10.0f;
      }
      value += decimal;
    }
    result.set_value(value * sign);
    result.set_valid(true);
    return result;
  }
} // namespace parser
