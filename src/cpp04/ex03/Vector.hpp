/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:07:23 by htsang            #+#    #+#             */
/*   Updated: 2023/09/24 01:15:57 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
class Vector
{
  public:
    Vector() : array_(new T[8]), size_(0), capacity_(8) {}

    Vector(size_t size) : array_(new T[size]), size_(0), capacity_(size) {}

    Vector(const Vector &copy)
    {
      *this = copy;
    }

    ~Vector()
    {
      delete[] array_;
    }

    Vector& operator=(const Vector &vector)
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

    T&  operator[](size_t index)
    {
      if (index >= size_)
        throw std::out_of_range("Index out of range");
      return array_[index];
    }

    T&  operator[](size_t index) const
    {
      if (index >= size_)
        throw std::out_of_range("Index out of range");
      return array_[index];
    }

    size_t size() const
    {
      return size_;
    }

    size_t capacity() const
    {
      return capacity_;
    }

    void clear()
    {
      size_ = 0;
    }

    void push_back(T value)
    {
      if (size_ == capacity_)
        resize();
      array_[size_++] = value;
    }
  
  protected:
    void  resize()
    {
      T* tmp = new T[capacity_ * 2];
      for (size_t i = 0; i < size_; i++)
        tmp[i] = array_[i];
      delete[] array_;
      array_ = tmp;
      capacity_ *= 2;
    }
  
  private:
    T*     array_;
    size_t size_;
    size_t capacity_;
};
