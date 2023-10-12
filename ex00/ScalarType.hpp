/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarType.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:27:46 by htsang            #+#    #+#             */
/*   Updated: 2023/10/12 19:25:52 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <limits>

#include "Result.hpp"

template <typename T>
class ScalarType
{
  public:
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

    ScalarType() : data_(T()), type_(kNormal) {}
    ScalarType(T c) : data_(c), type_(kNormal) {}
    ScalarType(enum Type type) : data_(T()), type_(type) {}
    ScalarType(ScalarType const& src) : data_(src.data_), type_(src.type_) {}
    ~ScalarType() {}
    ScalarType&  operator=(ScalarType const& src)
    {
      if (this != &src)
      {
        data_ = src.data_;
        type_ = src.type_;
      }
      return (*this);
    }

    T data() const { return data_;}

    Result<char, enum Error>  to_char() const
    {
      enum  Error error = checkError<char>();
      if (error == kNoError)
        return Result<char, enum Error>(static_cast<char>(data_));
      else if (!isprint(static_cast<int>(data_)))
        return Result<char, enum Error>(kNonDisplayableError);
      else
        return Result<char, enum Error>(static_cast<char>(data_));
    }

    Result<int, enum Error>  to_int() const
    {
      enum  Error error = checkError<int>();
      if (error == kNoError)
        return Result<int, enum Error>(static_cast<int>(data_));
      else
        return Result<int, enum Error>(error);
    }

    Result<float, enum Error>  to_float() const
    {
      enum  Error error = checkError<float>();
      if (error == kNoError)
        return Result<float, enum Error>(static_cast<float>(data_));
      else
        return Result<float, enum Error>(error);
    }

    Result<double, enum Error>  to_double() const
    {
      enum  Error error = checkError<double>();
      if (error == kNoError)
        return Result<double, enum Error>(static_cast<double>(data_));
      else
        return Result<double, enum Error>(error);
    }

  private:
    T    data_;
    Type type_;

    template<typename T2>
    bool  is_in_range() const
    {
      return (std::numeric_limits<T2>::min() <= data_ && data_ <= std::numeric_limits<T2>::max());
    }

    template <typename T2>
    enum Error  checkError() const
    {
      if (type_ == kNan)
        return kNanError;
      else if (type_ == kPositiveInfinity)
        return kPositiveInfinityError;
      else if (type_ == kNegativeInfinity)
        return kNegativeInfinityError;
      else if (!is_in_range<T2>())
        return kImpossibleError;
      else
        return kNoError;
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, typename ScalarType<T>::Error const& error)
{
  switch (error)
  {
    case ScalarType<T>::kNonDisplayableError:
      os << "Non displayable";
      break;
    case ScalarType<T>::kImpossibleError:
      os << "impossible";
      break;
    default:
      break;
  }
  return (os);
}

template <>
std::ostream& operator<<<float>(std::ostream& os, ScalarType<float>::Error const& error)
{
  switch (error)
  {
    case ScalarType<float>::kNonDisplayableError:
      os << "Non displayable";
      break;
    case ScalarType<float>::kImpossibleError:
      os << "impossible";
      break;
    case ScalarType<float>::kNanError:
      os << "nanf";
      break;
    case ScalarType<float>::kPositiveInfinityError:
      os << "+inff";
      break;
    case ScalarType<float>::kNegativeInfinityError:
      os << "-inff";
      break;
    default:
      break;
  }
  return (os);
}

template <>
std::ostream& operator<<<double>(std::ostream& os, ScalarType<double>::Error const& error)
{
  switch (error)
  {
    case ScalarType<double>::kNonDisplayableError:
      os << "Non displayable";
      break;
    case ScalarType<double>::kImpossibleError:
      os << "impossible";
      break;
    case ScalarType<double>::kNanError:
      os << "nan";
      break;
    case ScalarType<double>::kPositiveInfinityError:
      os << "+inf";
      break;
    case ScalarType<double>::kNegativeInfinityError:
      os << "-inf";
      break;
    default:
      break;
  }
  return (os);
}
