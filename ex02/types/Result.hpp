/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Result.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:35:42 by htsang            #+#    #+#             */
/*   Updated: 2023/12/11 00:58:09 by htsang           ###   ########.fr       */
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

    ///////////////////////////////////////////
    ////////////   Result monads   ////////////
    ///////////////////////////////////////////

    template <typename T2>
    Result<T2, Err> chain(Result<T2, Err> (*f)()) const;

    template <typename T2>
    Result<T2, Err> chain(Result<T2, Err> (*f)(T)) const;

    template <typename T2, typename ExtraData>
    Result<T2, Err> chain(Result<T2, Err> (*f)(ExtraData), ExtraData data) const;

    template <typename T2, typename ExtraData>
    Result<T2, Err> chain(Result<T2, Err> (*f)(ExtraData&), ExtraData& data) const;

    template <typename T2, typename ExtraData>
    Result<T2, Err> chain(Result<T2, Err> (*f)(T, ExtraData), ExtraData data) const;

    template <typename T2, typename ExtraData>
    Result<T2, Err> chain(Result<T2, Err> (*f)(T, ExtraData&), ExtraData& data) const;

    //////////////////////////////////////////////////////
    ////////////   Result monad for methods   ////////////
    //////////////////////////////////////////////////////

    template <typename T2, typename Class>
    Result<T2, Err> chain(T2 (Class::*f)(), Class& obj) const;

    template <typename T2, typename Class>
    Result<T2, Err> chain(T2 (Class::*f)(T), Class& obj) const;

    template <typename T2, typename Class, typename ExtraData>
    Result<T2, Err> chain(T2 (Class::*f)(ExtraData), Class& obj, ExtraData data) const;

    template <typename T2, typename Class, typename ExtraData>
    Result<T2, Err> chain(T2 (Class::*f)(ExtraData&), Class& obj, ExtraData& data) const;

    template <typename T2, typename Class, typename ExtraData>
    Result<T2, Err> chain(T2 (Class::*f)(T, ExtraData), Class& obj, ExtraData data) const;

    template <typename T2, typename Class, typename ExtraData>
    Result<T2, Err> chain(T2 (Class::*f)(T, ExtraData&), Class& obj, ExtraData& data) const;

  private:
    bool  is_ok_;
    T     value_;
    Err   error_;
};

template<typename T, typename Err>
std::ostream& operator<<(std::ostream& os, Result<T,Err> const& result);

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

///////////////////////////////////////////
////////////   Result monads   ////////////
///////////////////////////////////////////

/**
 * @brief Result monad.
 * @param f a function that takes no argument and returns a Result
 * @note chain:: Result a err -> (() -> Result b err) -> Result b err
*/
template <typename T, typename Err>
template <typename T2>
Result<T2, Err> Result<T,Err>::chain(Result<T2, Err> (*f)()) const
{
  if (is_ok_)
    return f();
  else
    return Result<T2, Err>::Error(error_);
}

/**
 * @brief Result monad.
 * @param f a function that takes the value of this Result and returns a Result
 * @note chain:: Result a err -> (a -> Result b err) -> Result b err
*/
template <typename T, typename Err>
template <typename T2>
Result<T2, Err> Result<T,Err>::chain(Result<T2, Err> (*f)(T)) const
{
  if (is_ok_)
    return f(value_);
  else
    return Result<T2, Err>::Error(error_);
}

/**
 * @brief Result monad.
 * @param f a function that takes an env and returns a Result
 * @param data the env
 * @note chain:: Result a err -> env -> ( env -> Result b env) -> Result b env
*/
template <typename T, typename Err>
template <typename T2, typename ExtraData>
Result<T2, Err> Result<T,Err>::chain(Result<T2, Err> (*f)(ExtraData), ExtraData data) const
{
  if (is_ok_)
    return f(data);
  else
    return Result<T2, Err>::Error(error_);
}

/**
 * @brief Result monad.
 * @param f a function that takes a reference to env and returns a Result
 * @param data The reference to env
 * @note chain:: Result a err -> env -> ( env -> Result b env) -> Result b env
*/
template <typename T, typename Err>
template <typename T2, typename ExtraData>
Result<T2, Err> Result<T,Err>::chain(Result<T2, Err> (*f)(ExtraData&), ExtraData& data) const
{
  if (is_ok_)
    return f(data);
  else
    return Result<T2, Err>::Error(error_);
}

/**
 * @brief Result monad.
 * @param f a function that takes a value of this Result and an env and returns a Result
 * @param data The env
 * @note chain:: Result a err -> env -> ( a -> env -> Result b env) -> Result b env
*/
template <typename T, typename Err>
template <typename T2, typename ExtraData>
Result<T2, Err> Result<T,Err>::chain(Result<T2, Err> (*f)(T, ExtraData), ExtraData data) const
{
  if (is_ok_)
    return f(value_, data);
  else
    return Result<T2, Err>::Error(error_);
}

/**
 * @brief Result monad.
 * @param f a function that takes a value of this Result and a reference to env and returns a Result
 * @param data The reference to env
 * @note chain:: Result a err -> env -> ( a -> env -> Result b env) -> Result b env
*/
template <typename T, typename Err>
template <typename T2, typename ExtraData>
Result<T2, Err> Result<T,Err>::chain(Result<T2, Err> (*f)(T, ExtraData&), ExtraData& data) const
{
  if (is_ok_)
    return f(value_, data);
  else
    return Result<T2, Err>::Error(error_);
}

//////////////////////////////////////////////////////
////////////   Result monad for methods   ////////////
//////////////////////////////////////////////////////

/**
 * @brief Result monad that is compatible with methods.
 * @param f a method that takes no argument and returns a Result
 * @param obj the object on which the method is called
 * @note chain:: Result a err -> (() -> Result b err) -> Result b err
*/
template <typename T, typename Err>
template <typename T2, typename Class>
Result<T2, Err> Result<T,Err>::chain(T2 (Class::*f)(), Class& obj) const
{
  if (is_ok_)
    return (obj.*f)();
  else
    return Result<T2, Err>::Error(error_);
}

/**
 * @brief Result monad that is compatible with methods.
 * @param f a method that takes the value of this Result and returns a Result
 * @param obj the object on which the method is called
 * @note chain:: Result a err -> (a -> Result b err) -> Result b err
*/
template <typename T, typename Err>
template <typename T2, typename Class>
Result<T2, Err> Result<T,Err>::chain(T2 (Class::*f)(T), Class& obj) const
{
  if (is_ok_)
    return (obj.*f)(value_);
  else
    return Result<T2, Err>::Error(error_);
}

/**
 * @brief Result monad that is compatible with methods.
 * @param f a method that takes an env and returns a Result
 * @param obj the object on which the method is called
 * @param data the env
 * @note chain:: Result a err -> env -> ( env -> Result b env) -> Result b env
*/
template <typename T, typename Err>
template <typename T2, typename Class, typename ExtraData>
Result<T2, Err> Result<T,Err>::chain(T2 (Class::*f)(ExtraData), Class& obj, ExtraData data) const
{
  if (is_ok_)
    return (obj.*f)(data);
  else
    return Result<T2, Err>::Error(error_);
}

/**
 * @brief Result monad that is compatible with methods.
 * @param f a method that takes a reference to env and returns a Result
 * @param obj the object on which the method is called
 * @param data The reference to env
 * @note chain:: Result a err -> env -> ( env -> Result b env) -> Result b env
*/
template <typename T, typename Err>
template <typename T2, typename Class, typename ExtraData>
Result<T2, Err> Result<T,Err>::chain(T2 (Class::*f)(ExtraData&), Class& obj, ExtraData& data) const
{
  if (is_ok_)
    return (obj.*f)(data);
  else
    return Result<T2, Err>::Error(error_);
}

/**
 * @brief Result monad that is compatible with methods.
 * @param f a method that takes a value of this Result and an env and returns a Result
 * @param obj the object on which the method is called
 * @param data The env
 * @note chain:: Result a err -> env -> ( a -> env -> Result b env) -> Result b env
*/
template <typename T, typename Err>
template <typename T2, typename Class, typename ExtraData>
Result<T2, Err> Result<T,Err>::chain(T2 (Class::*f)(T, ExtraData), Class& obj, ExtraData data) const
{
  if (is_ok_)
    return (obj.*f)(value_, data);
  else
    return Result<T2, Err>::Error(error_);
}

/**
 * @brief Result monad that is compatible with methods.
 * @param f a method that takes a value of this Result and a reference to env and returns a Result
 * @param obj the object on which the method is called
 * @param data The reference to env
 * @note chain:: Result a err -> env -> ( a -> env -> Result b env) -> Result b env
*/
template <typename T, typename Err>
template <typename T2, typename Class, typename ExtraData>
Result<T2, Err> Result<T,Err>::chain(T2 (Class::*f)(T, ExtraData&), Class& obj, ExtraData& data) const
{
  if (is_ok_)
    return (obj.*f)(value_, data);
  else
    return Result<T2, Err>::Error(error_);
}

template<typename T, typename Err>
std::ostream& operator<<(std::ostream& os, Result<T,Err> const& result)
{
  if (result.is_ok())
    os << result.value();
  else
    os << result.error();
  return os;
}
