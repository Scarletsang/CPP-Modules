/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Result.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:20:02 by htsang            #+#    #+#             */
/*   Updated: 2023/09/13 23:01:59 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ResultInternal.hpp"

namespace parser
{
  template <typename T>
  class Result : public ResultInternal
  {
    public:
      Result() : ResultInternal() {}
      Result(std::string string) : ResultInternal(string) {}
      ~Result() {}
      Result(const Result& result)
        : ResultInternal(result),
          result_(result.result_) {}
      const Result& operator=(const Result& result)
      {
        if (this == &result)
          return *this;
        ResultInternal::operator=(result);
        result_ = result.result_;
        return *this;
      }

      T &value() const
      {
        return const_cast<T &>(result_);
      }

      void  set_value(T value)
      {
        result_ = value;
        set_valid(true);
      }

      template <typename U>
      U chain(Result<U> result)
      {
        set_string(result.string());
        set_valid(result.is_valid());
        return result.value();
      }

    private:
      T result_;
  };
} // namespace parser
