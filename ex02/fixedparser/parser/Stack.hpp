/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:53:40 by htsang            #+#    #+#             */
/*   Updated: 2023/09/18 00:22:07 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

template <typename T>
class Stack
{
  public:
    static const size_t kDefaultCapacity = 8;

    Stack()
      : stack_(new T[kDefaultCapacity]),
        size_(0),
        capacity_(kDefaultCapacity) {};

    Stack(const Stack& stack)
    {
      *this = stack;
    }

    Stack &operator=(const Stack& stack)
    {
      if (this == &stack)
        return *this;
      delete[] stack_;
      stack_ = new T[stack.capacity_];
      size_ = stack.size_;
      capacity_ = stack.capacity_;
      for (size_t i = 0; i < size_; i++)
        stack_[i] = stack.stack_[i];
      return *this;
    }

    ~Stack()
    {
      delete[] stack_;
    }

    void push(T value)
    {
      if (size_ == capacity_)
        resize();
      stack_[size_++] = value;
    }

    size_t size() const
    {
      return size_;
    }

    T pop()
    {
      if (size_ == 0)
        throw std::string("Stack is empty");
      return stack_[--size_];
    }

    T peek()
    {
      if (size_ == 0)
        throw std::string("Stack is empty");
      return stack_[size_ - 1];
    }

    bool  is_empty() const
    {
      return size_ == 0;
    }

    void  clear()
    {
      size_ = 0;
    }
  
  protected:
    void  resize()
    {
      T *new_stack = new T[capacity_ * 2];
      for (size_t i = 0; i < size_; i++)
        new_stack[i] = stack_[i];
      delete[] stack_;
      stack_ = new_stack;
      capacity_ *= 2;
    }
  
  private:
    T*      stack_;
    size_t  size_;
    size_t  capacity_;
};
