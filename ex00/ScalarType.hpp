/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarType.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:27:46 by htsang            #+#    #+#             */
/*   Updated: 2023/10/10 21:35:21 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ScalarType
{
  public:
    union Type
    {
      char    c;
      int     i;
      float   f;
      double  d;
    };

    enum  TypeName
    {
      kChar,
      kInt,
      kFloat,
      kDouble
    };

    ScalarType();
    ScalarType(ScalarType const& src);
    ~ScalarType();
    ScalarType&  operator=(ScalarType const& src);
  
  private:
    union Type      data_;
    enum  TypeName  type_;
};

std::ostream& operator<<(std::ostream& os, ScalarType const& scalar_type);
