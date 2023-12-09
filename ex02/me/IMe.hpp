/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMe.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:49:53 by htsang            #+#    #+#             */
/*   Updated: 2023/12/07 20:20:30 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>

#include "Maybe.hpp"

template <typename T>
class IMe
{
  public:
    typedef T value_type;
    virtual ~IMe() {};

    virtual T&        operator[](size_t position) = 0;
    virtual const T&  operator[](size_t position) const = 0;

    virtual bool      empty() const = 0;
    virtual size_t    size() const = 0;
    virtual Maybe<T>  back() const = 0;

    virtual Maybe<T>  pop_back() = 0;
    virtual void      push_back(T value) = 0;
    virtual int       insert(size_t position, T value) = 0;
    virtual int       erase(size_t position) = 0;
    virtual void      clear() = 0;

    template <typename Container>
    Container map(typename Container::value_type (*f)(T)) const;

    template <typename Accu>
    Accu      reduce(void (*f)(Accu&, T), Accu accu) const;
};

template <typename T>
template <typename Container>
Container IMe<T>::map(typename Container::value_type (*f)(T)) const
{
  Container newMe;

  for (size_t i = 0; i < this->size(); i++)
  {
    newMe.push_back(f((*this)[i]));
  }
  return newMe;
}

template <typename T>
template <typename Accu>
Accu IMe<T>::reduce(void (*f)(Accu&, T), Accu accu) const
{
  for (size_t i = 0; i < this->size(); i++)
  {
    f(accu, (*this)[i]);
  }
  return accu;
}
