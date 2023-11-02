/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:07:23 by htsang            #+#    #+#             */
/*   Updated: 2023/11/02 23:04:48 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
class Vector
{
  public:
    Vector();
    Vector(size_t size);
    Vector(const Vector &copy);
    ~Vector();

    Vector& operator=(const Vector &vector);
    T&  operator[](size_t index);
    T&  operator[](size_t index) const;

    size_t size() const;
    size_t capacity() const;
    void clear();
    void push_back(T value);
  
  protected:
    void  resize();
  
  private:
    T*     array_;
    size_t size_;
    size_t capacity_;
};

/////////////////////////////////////////////////////
////////////   template implementation   ////////////
/////////////////////////////////////////////////////

template <typename T>
Vector<T>::Vector()
  : array_(new T[8]),
    size_(0),
    capacity_(8) {}

template <typename T>
Vector<T>::Vector(size_t size)
  : array_(new T[size]),
    size_(0),
    capacity_(size) {}

template <typename T>
Vector<T>::Vector(const Vector &copy)
{
  *this = copy;
}

template <typename T>
Vector<T>::~Vector()
{
  delete[] array_;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector &vector)
{
  if (this != &vector)
  {
    delete[] array_;
    array_ = new T[vector.capacity_];
    for (size_t i = 0; i < vector.size_; i++)
      array_[i] = vector.array_[i];
    size_ = vector.size_;
    capacity_ = vector.capacity_;
  }
  return (*this);
}

template <typename T>
T&  Vector<T>::operator[](size_t index)
{
  if (index >= size_)
    throw std::out_of_range("Index out of range");
  return array_[index];
}

template <typename T>
T&  Vector<T>::operator[](size_t index) const
{
  if (index >= size_)
    throw std::out_of_range("Index out of range");
  return array_[index];
}

template <typename T>
size_t Vector<T>::size() const
{
  return size_;
}

template <typename T>
size_t Vector<T>::capacity() const
{
  return capacity_;
}

template <typename T>
void Vector<T>::clear()
{
  size_ = 0;
}

template <typename T>
void Vector<T>::push_back(T value)
{
  if (size_ == capacity_)
    resize();
  array_[size_++] = value;
}

template <typename T>
void  Vector<T>::resize()
{
  T* tmp = new T[capacity_ * 2];
  for (size_t i = 0; i < size_; i++)
    tmp[i] = array_[i];
  delete[] array_;
  array_ = tmp;
  capacity_ *= 2;
}
