/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Box.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:13:38 by htsang            #+#    #+#             */
/*   Updated: 2023/12/09 21:12:35 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>

#include <iostream>
#include <typeinfo>

template <typename T>
class Box
{
  public:
    Box(const T& value);
    Box(T** value);
    Box(Box<T> &other);
    ~Box();
  
    Box<T>& operator=(const Box<T> &other);
    T       operator*() const;
    T*      operator->() const;

    

    template <typename U>
    operator Box<U>() const;

  private:
    T*    value_;
    bool  is_borrowed_;
};

/////////////////////////////////////////////////////
////////////   template implementation   ////////////
/////////////////////////////////////////////////////

template <typename T>
Box<T>::Box(const T& value)
  : value_(new T(value)) {}

template <typename T>
Box<T>::Box(T** value)
  : value_(*value)
{
  *value = NULL;
}

template <typename T>
Box<T>::Box(Box<T> &other)
  : value_(other.value_)
{
  other.value_ = NULL;
}

template <typename T>
Box<T>::~Box()
{
  delete value_;
}

template <typename T>
Box<T>& Box<T>::operator=(const Box<T> &other)
{
  if (this != &other)
  {
    delete value_;
    value_ = new T(*other.value_);
  }
  return *this;
}

template <typename T>
T Box<T>::operator*() const
{
  return *value_;
}

template <typename T>
T* Box<T>::operator->() const
{
  return value_;
}

template <typename T>
template <typename U>
Box<T>::operator Box<U>() const
{
  std::cout << "cast: " << typeid(U).name() << " " << typeid(T).name() << std::endl;
  U*  value = dynamic_cast<U*>(value_);
  if (value == NULL)
    throw std::bad_cast();
  else
  {
    return ;
  }
}
