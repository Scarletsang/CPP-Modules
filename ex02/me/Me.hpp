/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Me.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 20:19:46 by htsang            #+#    #+#             */
/*   Updated: 2023/12/07 23:09:32 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>

#include <vector>
#include <iterator>

#include "IMe.hpp"

template <typename T>
class Me : public IMe
{
  public:
    Me();
    Me(const Me &copy);
    ~Me();
    Me& operator=(const Me &copy);

    int&        operator[](size_t position);
    const int&  operator[](size_t position) const;

    bool      empty() const;
    size_t    size() const;
    int       back() const;

    void      push_back(int value);
    int       pop_back();
    int       insert(size_t position, int value);
    int       erase(size_t position);
    void      clear();

  private:
    T  container_;
};

/////////////////////////////////////////////////////
////////////   template implementation   ////////////
/////////////////////////////////////////////////////

template <typename T>
Me<T>::Me()
  : container_() {}

template <typename T>
Me<T>::Me(const Me &copy)
  : container_(copy.container_) {}

template <typename T>
Me<T>::~Me() {}

template <typename T>
Me<T>& Me<T>::operator=(const Me &copy)
{
  if (this != &copy)
    container_ = copy.container_;
  return *this;
}

template <typename T>
int& Me<T>::operator[](size_t position)
{
  return container_[position];
}

template <typename T>
const int& Me<T>::operator[](size_t position) const
{
  return container_[position];
}

template <typename T>
bool Me<T>::empty() const
{
  return container_.empty();
}

template <typename T>
size_t Me<T>::size() const
{
  return container_.size();
}

template <typename T>
int Me<T>::back() const
{
  return container_.back();
}

template <typename T>
void Me<T>::push_back(int value)
{
  container_.push_back(value);
}

template <typename T>
int Me<T>::pop_back()
{
  int value = container_.back();
  container_.pop_back();
  return value;
}

template <typename T>
int Me<T>::insert(size_t position, int value)
{
  if (position > container_.size())
    return EXIT_FAILURE;
  else
  {
    typename T::iterator it = container_.begin();
    std::advance(it, position);
    container_.insert(it, value);
    return EXIT_SUCCESS;
  }
}

template <typename T>
int Me<T>::erase(size_t position)
{
  if (position > container_.size())
    return EXIT_FAILURE;
  else
  {
    typename T::iterator it = container_.begin();
    std::advance(it, position);
    container_.erase(it);
    return EXIT_SUCCESS;
  }
}

template <typename T>
void Me<T>::clear()
{
  container_.clear();
}
