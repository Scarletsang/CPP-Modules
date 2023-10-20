/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Result.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:35:42 by htsang            #+#    #+#             */
/*   Updated: 2023/10/20 14:17:02 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T, typename Err>
class Result
{
  public:
    Result(T value);
    Result(Err error);
    Result(Result const &src);
    ~Result();

    Result &operator=(Result const &src);

    bool  is_ok() const;

    T     value() const;
    Err   error() const;

  private:
    union {
      T   value;
      Err error;
    }     data_;
    bool  is_ok_;
};

/////////////////////////////////////////////////////
////////////   template implementation   ////////////
/////////////////////////////////////////////////////

template <typename T, typename Err>
Result<T,Err>::Result(T value) : is_ok_(true) { data_.value = value; }

template <typename T, typename Err>
Result<T,Err>::Result(Err error) { data_.error = error; }

template <typename T, typename Err>
Result<T,Err>::Result(Result const &src) : data_(src.data_), is_ok_(src.is_ok_) {}

template <typename T, typename Err>
Result<T,Err>::~Result() {}

template <typename T, typename Err>
Result<T,Err>&  Result<T,Err>::operator=(Result const &src)
{
  if (this != &src)
  {
    data_  = src.data_;
    is_ok_ = src.is_ok_;
  }
  return (*this);
}

template <typename T, typename Err>
bool  Result<T,Err>::is_ok() const { return (is_ok_); }

template <typename T, typename Err>
T Result<T,Err>::value() const { return (data_.value); }

template <typename T, typename Err>
Err Result<T,Err>::error() const { return (data_.error); }

template<typename T, typename Err>
std::ostream& operator<<(std::ostream& os, Result<T,Err> const& result)
{
  if (result.is_ok())
    os << result.value();
  else
    os << result.error();
  return (os);
}
