/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 22:06:48 by htsang            #+#    #+#             */
/*   Updated: 2023/10/20 22:20:26 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <limits>

#include "Result.hpp"

namespace convert
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

  enum  Type
  {
    kNormal,
    kNan,
    kPositiveInfinity,
    kNegativeInfinity
  };

  template <typename T>
  class Scalar
  {
    public:

      Scalar();
      Scalar(T c);
      Scalar(enum Type type);
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
      Type type_;

      template <typename T2>
      Error  checkError() const;
  };

  template<typename T, typename Range>
  bool  IsInRange(T value)
  {
    return (value >= std::numeric_limits<Range>::min() &&
            value <= std::numeric_limits<Range>::max());
  }

  /////////////////////////////////////////////////////
  ////////////   template implementation   ////////////
  /////////////////////////////////////////////////////

  template <typename T>
  Scalar<T>::Scalar() : data_(T()), type_(kNormal) {}

  template <typename T>
  Scalar<T>::Scalar(T c) : data_(c), type_(kNormal) {}

  template <typename T>
  Scalar<T>::Scalar(enum Type type) : data_(T()), type_(type) {}

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
    if (error == kNoError)
      return Result<char, Error>(static_cast<char>(data_));
    else if (!isprint(static_cast<int>(data_)))
      return Result<char, Error>(kNonDisplayableError);
    else
      return Result<char, Error>(static_cast<char>(data_));
  }

  template <typename T>
  Result<int, Error>  Scalar<T>::to_int() const
  {
    enum  Error error = checkError<int>();
    if (error == kNoError)
      return Result<int, Error>(static_cast<int>(data_));
    else
      return Result<int, Error>(error);
  }

  template <typename T>
  Result<float, Error>  Scalar<T>::to_float() const
  {
    enum  Error error = checkError<float>();
    if (error == kNoError)
      return Result<float, Error>(static_cast<float>(data_));
    else
      return Result<float, Error>(error);
  }

  template <typename T>
  Result<double, Error>  Scalar<T>::to_double() const
  {
    enum  Error error = checkError<double>();
    if (error == kNoError)
      return Result<double, Error>(static_cast<double>(data_));
    else
      return Result<double, Error>(error);
  }

  /////////////////////////////////////////////
  ////////////   private methods   ////////////
  /////////////////////////////////////////////

  template<typename T>
  template<typename T2>
  Error  Scalar<T>::checkError() const
  {
    if (type_ == kNan)
      return kNanError;
    else if (type_ == kPositiveInfinity)
      return kPositiveInfinityError;
    else if (type_ == kNegativeInfinity)
      return kNegativeInfinityError;
    else if (!IsInRange<T, T2>(data_))
      return kImpossibleError;
    else
      return kNoError;
  }

  ////////////////////////////////////////////////
  ////////////   Printing functions   ////////////
  ////////////////////////////////////////////////

  template <typename T>
  std::ostream& operator<<(std::ostream& os, Error const& error)
  {
    switch (error)
    {
      case kNonDisplayableError:
        os << "Non displayable";
        break;
      case kImpossibleError:
        os << "impossible";
        break;
      default:
        break;
    }
    return (os);
  }

  template <>
  std::ostream& operator<<<float>(std::ostream& os, Error const& error)
  {
    switch (error)
    {
      case kNonDisplayableError:
        os << "Non displayable";
        break;
      case kImpossibleError:
        os << "impossible";
        break;
      case kNanError:
        os << "nanf";
        break;
      case kPositiveInfinityError:
        os << "+inff";
        break;
      case kNegativeInfinityError:
        os << "-inff";
        break;
      default:
        break;
    }
    return (os);
  }

  template <>
  std::ostream& operator<<<double>(std::ostream& os, Error const& error)
  {
    switch (error)
    {
      case kNonDisplayableError:
        os << "Non displayable";
        break;
      case kImpossibleError:
        os << "impossible";
        break;
      case kNanError:
        os << "nan";
        break;
      case kPositiveInfinityError:
        os << "+inf";
        break;
      case kNegativeInfinityError:
        os << "-inf";
        break;
      default:
        break;
    }
    return (os);
  }
} // namespace scalar
