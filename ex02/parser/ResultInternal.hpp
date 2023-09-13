/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResultInternal.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:20:02 by htsang            #+#    #+#             */
/*   Updated: 2023/09/13 22:58:14 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

namespace parser
{
  class ResultInternal
  {
    public:
      ResultInternal();
      ResultInternal(std::string string);
      ~ResultInternal();
      ResultInternal(const ResultInternal& value);
      const ResultInternal& operator=(const ResultInternal& value);

      /* validators */

      bool  is_valid() const;
      bool  is_end() const;

      /* getters */

      std::string &string() const;

      /* setters */

      void  set_valid(bool is_valid);
      void  set_string(std::string string);

      void  advance(size_t n);

    private:
      std::string string_;
      bool        is_valid_;
  };
} // namespace parser