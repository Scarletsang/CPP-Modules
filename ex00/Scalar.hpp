/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 22:06:48 by htsang            #+#    #+#             */
/*   Updated: 2023/10/28 17:11:53 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <limits>

#include "Result.hpp"

namespace converter
{
  enum  Error
  {
    kNonDisplayableError,
    kImpossibleError,
    kNanError,
    kPositiveInfinityError,
    kNegativeInfinityError,
    kNoError
  };

  typedef struct ScalarType
  {
    enum Value {
      kNormal,
      kNan,
      kPositiveInfinity,
      kNegativeInfinity
    } value;

    static ScalarType Normal();
    static ScalarType Nan();
    static ScalarType PositiveInfinity();
    static ScalarType NegativeInfinity();
    ScalarType(enum Value value);
  } ScalarType;

  template <typename T>
  class Scalar
  {
    public:

      Scalar();
      Scalar(T c);
      Scalar(ScalarType type);
      Scalar(Scalar const& src);
      ~Scalar();
      Scalar&  operator=(Scalar const& src);

      T data() const;

      Result<char, Error>  to_char() const;

      Result<int, Error>  to_int() const;

      Result<float, Error>  to_float() const;

      Result<double, Error>  to_double() const;

    private:
      T    data_;
      ScalarType type_;

      template <typename T2>
      Error  checkError() const;
  };

  /////////////////////////////////////////////////////
  ////////////   template implementation   ////////////
  /////////////////////////////////////////////////////

  template<typename T>
  T MinimumValue()
  {
    T min = std::numeric_limits<T>::min();
    if (min > 0)
      return -std::numeric_limits<T>::max();
    else
      return min;
  }

  template <typename T>
  Scalar<T>::Scalar() : data_(T()), type_(ScalarType::kNormal) {}

  template <typename T>
  Scalar<T>::Scalar(T c) : data_(c), type_(ScalarType::kNormal) {}

  template <typename T>
  Scalar<T>::Scalar(ScalarType type) : data_(T()), type_(type) {}

  template <typename T>
  Scalar<T>::Scalar(Scalar const& src) : data_(src.data_), type_(src.type_) {}

  template <typename T>
  Scalar<T>::~Scalar() {}

  template <typename T>
  Scalar<T>&  Scalar<T>::operator=(Scalar const& src)
  {
    if (this != &src)
    {
      data_ = src.data_;
      type_ = src.type_;
    }
    return (*this);
  }

  template <typename T>
  T Scalar<T>::data() const { return data_; }

  ////////////////////////////////////////////////
  ////////////   conversion methods   ////////////
  ////////////////////////////////////////////////

  template <typename T>
  Result<char, Error>  Scalar<T>::to_char() const
  {
    enum  Error error = checkError<char>();
    if (error != kNoError)
      return Result<char, Error>::Error(error);
    else if (!isprint(static_cast<int>(data_)))
      return Result<char, Error>::Error(kNonDisplayableError);
    else
      return Result<char, Error>::Ok(static_cast<char>(data_));
  }

  template <typename T>
  Result<int, Error>  Scalar<T>::to_int() const
  {
    enum  Error error = checkError<int>();
    if (error == kNoError)
      return Result<int, Error>::Ok(static_cast<int>(data_));
    else
      return Result<int, Error>::Error(error);
  }

  template <typename T>
  Result<float, Error>  Scalar<T>::to_float() const
  {
    enum  Error error = checkError<float>();
    if (error == kNoError)
      return Result<float, Error>::Ok(static_cast<float>(data_));
    else
      return Result<float, Error>::Error(error);
  }

  template <typename T>
  Result<double, Error>  Scalar<T>::to_double() const
  {
    enum  Error error = checkError<double>();
    if (error == kNoError)
      return Result<double, Error>::Ok(static_cast<double>(data_));
    else
      return Result<double, Error>::Error(error);
  }

  /////////////////////////////////////////////
  ////////////   private methods   ////////////
  /////////////////////////////////////////////

  template<typename T, typename Range>
  static bool  IsInRange(T value)
  {
    return (value >= MinimumValue<Range>() &&
            value <= std::numeric_limits<Range>::max());
  }

  template<typename T>
  template<typename T2>
  Error  Scalar<T>::checkError() const
  {
    switch (type_.value)
    {
    case ScalarType::kNan:
      return kNanError;
    case ScalarType::kPositiveInfinity:
      return kPositiveInfinityError;
    case ScalarType::kNegativeInfinity:
      return kNegativeInfinityError;
    default:
      if (!IsInRange<T, T2>(data_))
        return kImpossibleError;
      else
        return kNoError;
    }
  }
} // namespace scalar
