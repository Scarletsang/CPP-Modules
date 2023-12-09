/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Me.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 20:19:46 by htsang            #+#    #+#             */
/*   Updated: 2023/12/09 17:19:20 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>

#include <vector>
#include <iterator>

#include "IMe.hpp"
#include "Maybe.hpp"

template <typename T>
class Me : public IMe<typename T::value_type>
{
  public:
    typedef typename T::value_type        value_type;
    typedef T                             container_type;
    Me();
    Me(const Me &copy);
    ~Me();
    Me& operator=(const Me &copy);

    value_type&       operator[](size_t position);
    const value_type& operator[](size_t position) const;

    bool              empty() const;
    size_t            size() const;
    Maybe<value_type> back() const;

    Maybe<value_type> pop_back();
    void              push_back(value_type value);
    int               insert(size_t position, value_type value);
    int               erase(size_t position);
    void              clear();

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
typename Me<T>::value_type& Me<T>::operator[](size_t position)
{
  return container_[position];
}

template <typename T>
const typename Me<T>::value_type& Me<T>::operator[](size_t position) const
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
Maybe<typename Me<T>::value_type> Me<T>::back() const
{
  if (container_.empty())
    return Nothing();
  return container_.back();
}

template <typename T>
Maybe<typename Me<T>::value_type> Me<T>::pop_back()
{
  Maybe<typename Me<T>::value_type> value = container_.back();
  if (value.is_ok())
    container_.pop_back();
  return value;
}

template <typename T>
void Me<T>::push_back(typename Me<T>::value_type value)
{
  container_.push_back(value);
}

template <typename T>
int Me<T>::insert(size_t position, typename Me<T>::value_type value)
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
