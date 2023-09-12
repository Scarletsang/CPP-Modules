/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Result.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:20:02 by htsang            #+#    #+#             */
/*   Updated: 2023/09/12 22:00:52 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ResultInternal.hpp"

namespace parser
{
  template <typename T>
  class Result : public ParserResultInternal
  {
    public:
      Result(std::string &string) : ResultInternal(string) {}
      ~Result() {}
      Result(const Result& result)
        : ParserResultInternal(result),
          result_(result.result_) {}
      const Result& operator=(const Result& result)
      {
        if (this == &result)
          return *this;
        ParserResultInternal::operator=(result);
        result_ = result.result_;
        return *this;
      }

      T value() const
      {
        return result_;
      }

      set_value(T value)
      {
        result_ = value;
      }

    private:
      T result_;
  };
} // namespace parser