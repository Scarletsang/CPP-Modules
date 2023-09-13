/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:20:02 by htsang            #+#    #+#             */
/*   Updated: 2023/09/13 23:19:35 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Result.hpp"

namespace parser
{
  struct Nothing {};

  Result<Nothing> Ignore(std::string input, char c);
  Result<Nothing> Ignore(std::string input, std::string string);
  Result<Nothing> IgnoreOneOf(std::string input, std::string set);

  Result<bool>  Expect(std::string input, char c);
  Result<bool>  Expect(std::string input, std::string string);
  Result<bool>  ExpectOneOf(std::string input, std::string set);

  Result<bool>  Match(std::string input, char c);
  Result<bool>  Match(std::string input, std::string string);
  Result<bool>  MatchOneOf(std::string input, std::string set);

  Result<char>  Char(std::string input);
  Result<char>  CharOf(std::string input, std::string set);
  Result<std::string> String(std::string input, std::string delimiter);

  Result<int>   Integer(std::string input);
  Result<float> Float(std::string input);

} // namespace parser
