/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResultInternal.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:20:02 by htsang            #+#    #+#             */
/*   Updated: 2023/09/12 22:00:40 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

namespace parser
{
  class ResultInternal
  {
    public:
      ResultInternal(std::string &string);
      ~ResultInternal();
      ResultInternal(const ResultInternal& value);
      const ResultInternal& operator=(const ResultInternal& parser);

      /* validators */

      bool  is_valid() const;
      bool  is_end() const;

      /* getters */

      std::string string() const;

      /* setters */

      void  set_valid(bool is_valid);
      void  advance(size_t n);
    
    private:
      std::string &string_;
      size_t      position_;
      bool        is_valid_;
  };
} // namespace parser