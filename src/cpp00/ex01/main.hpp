/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 22:40:07 by htsang            #+#    #+#             */
/*   Updated: 2023/07/18 01:38:54 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MAIN_HPP
# define MAIN_HPP

# include <string>

namespace my
{
  class NumericString : public std::string {
    public:
      NumericString& operator=(const char* str)
      {
        std::string::operator=(str);
        return *this;
      }
  };
} // namespace my

#endif