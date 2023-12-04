/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:01:50 by htsang            #+#    #+#             */
/*   Updated: 2023/12/04 23:54:00 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
  public:
    typedef typename Container::iterator iterator;
    MutantStack();
    MutantStack(const MutantStack& copy);
    ~MutantStack();

    MutantStack& operator=(const MutantStack& copy);

    iterator begin();
    iterator end();

    void  push_back(const T& value);
    void  pop_back();
    T&          back();
    const T&    back() const;
};

/////////////////////////////////////////////////////
////////////   template implementation   ////////////
/////////////////////////////////////////////////////

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack()
  : std::stack<T, Container>() {}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& copy)
  : std::stack<T, Container>(copy) {}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack() {}

template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& copy)
{
  if (this == &copy)
    return *this;
  std::stack<T, Container>::operator=(copy);
  return *this;
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
  return this->c.begin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
  return this->c.end();
}

template <typename T, typename Container>
void  MutantStack<T, Container>::push_back(const T& value)
{
  this->push(value);
}

template <typename T, typename Container>
void  MutantStack<T, Container>::pop_back()
{
  this->pop();
}

template <typename T, typename Container>
T&          MutantStack<T, Container>::back()
{
  return this->top();
}

template <typename T, typename Container>
const T&    MutantStack<T, Container>::back() const
{
  return this->top();
}
