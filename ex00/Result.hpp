/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Result.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:35:42 by htsang            #+#    #+#             */
/*   Updated: 2023/10/12 18:58:12 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T, typename Err>
class Result
{
  public:
    Result(T value) : is_ok_(true) { data_.value = value; }
    Result(Err error) : is_ok_(false) { data_.error = error; }
    Result(Result const &src) : data_(src.data_), is_ok_(src.is_ok_) {};
    ~Result() {};

    Result &operator=(Result const &src)
    {
      if (this != &src)
      {
        data_  = src.data_;
        is_ok_ = src.is_ok_;
      }
      return (*this);
    };

    bool  is_ok() const { return is_ok_; };

    T     value() const { return data_.value; };
    Err   error() const { return data_.error; };

  private:
    union {
      T   value;
      Err error;
    }     data_;
    bool  is_ok_;
};

template<typename T, typename Err>
std::ostream& operator<<(std::ostream& os, Result<T,Err> const& result)
{
  if (result.is_ok())
    os << result.value();
  else
    os << result.error();
  return (os);
}
