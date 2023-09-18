/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedToken.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 23:28:18 by htsang            #+#    #+#             */
/*   Updated: 2023/09/17 23:43:05 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

struct FixedToken
{
  enum Type
  {
    kNone,
    kNumber,
    kPlus,
    kMinus,
    kMultiply,
    kDivide,
    kOpenParenthesis,
    kCloseParenthesis,
  };

  Type        type;
  std::string value;

  FixedToken(Type type, std::string value)
    : type(type),
      value(value) {}
};
