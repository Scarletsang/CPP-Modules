/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:04:52 by htsang            #+#    #+#             */
/*   Updated: 2023/11/02 14:13:55 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
class Array
{
  public:
    Array();
    Array(unsigned int n);
    Array(Array const &other);
    ~Array();
    Array&  operator=(Array const &other);

    T& operator[](unsigned int index);
    unsigned int size() const;

  private:
    T*            array_;
    unsigned int  size_;
};

/////////////////////////////////////////////////////
////////////   template implementation   ////////////
/////////////////////////////////////////////////////

template <typename T>
Array<T>::Array() : array_(NULL), size_(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : array_(new T[n]), size_(n) {}

template <typename T>
Array<T>::Array(Array const &other) : array_(new T[other.size_]), size_(other.size_)
{
  for (unsigned int i = 0; i < size_; i++)
    array_[i] = other.array_[i];
}

template <typename T>
Array<T>::~Array()
{
  if (array_)
    delete[] array_;
}

template <typename T>
Array<T>& Array<T>::operator=(Array const &other)
{
  if (this != &other)
  {
    if (array_)
      delete[] array_;
    array_ = new T[other.size_];
    size_ = other.size_;
    for (unsigned int i = 0; i < size_; i++)
      array_[i] = other.array_[i];
  }
  return *this;
}

template <typename T>
T&  Array<T>::operator[](unsigned int index)
{
  if (index >= size_)
    throw std::out_of_range("Index out of range");
  return array_[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
  return size_;
}
