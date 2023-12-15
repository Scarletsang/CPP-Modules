/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Result.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:35:42 by htsang            #+#    #+#             */
/*   Updated: 2023/10/28 00:02:02 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T, typename Err>
class Result
{
  public:
    static  Result Ok(T value);
    static  Result Error(Err error);

    Result(T value);
    Result(Err error, int);
    Result(Result const &src);
    ~Result();

    Result &operator=(Result const &src);

    bool  is_ok() const;

    T     value() const;
    Err   error() const;

  private:
    bool  is_ok_;
    T     value_;
    Err   error_;
};

/////////////////////////////////////////////////////
////////////   template implementation   ////////////
/////////////////////////////////////////////////////

template <typename T, typename Err>
Result<T,Err> Result<T,Err>::Ok(T value) { return Result<T,Err>(value); }

template <typename T, typename Err>
Result<T,Err> Result<T,Err>::Error(Err error) { return Result<T,Err>(error, 0); }

template <typename T, typename Err>
Result<T,Err>::Result(T value) : is_ok_(true), value_(value) {}

template <typename T, typename Err>
Result<T,Err>::Result(Err error, int) : is_ok_(false), error_(error) {}

template <typename T, typename Err>
Result<T,Err>::Result(Result const &src) : is_ok_(src.is_ok_) {
  if (is_ok_)
    value_ = src.value_;
  else
    error_ = src.error_;
}

template <typename T, typename Err>
Result<T,Err>::~Result() {}

template <typename T, typename Err>
Result<T,Err>&  Result<T,Err>::operator=(Result const &src)
{
  if (this != &src)
  {
    if (src.is_ok_)
      value_ = src.value_;
    else
      error_ = src.error_;
    is_ok_ = src.is_ok_;
  }
  return *this;
}

template <typename T, typename Err>
bool  Result<T,Err>::is_ok() const { return is_ok_; }

template <typename T, typename Err>
T Result<T,Err>::value() const { return value_; }

template <typename T, typename Err>
Err Result<T,Err>::error() const { return error_; }

template<typename T, typename Err>
std::ostream& operator<<(std::ostream& os, Result<T,Err> const& result)
{
  if (result.is_ok())
    os << result.value();
  else
    os << result.error();
  return os;
}
