/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InteractiveMutantStack.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:23:42 by htsang            #+#    #+#             */
/*   Updated: 2023/12/05 15:48:32 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InteractiveMutantStack.hpp"
#include "interactive/Data.hpp"

InteractiveMutantStack::InteractiveMutantStack()
  : interactive::Data() {}

InteractiveMutantStack::InteractiveMutantStack(const InteractiveMutantStack& interactiveMutantStack)
  : interactive::Data(interactiveMutantStack) {}

InteractiveMutantStack::~InteractiveMutantStack() {}

const InteractiveMutantStack& InteractiveMutantStack::operator=(const InteractiveMutantStack& interactiveMutantStack)
{
  if (this != &interactiveMutantStack)
  {
    interactive::Data::operator=(interactiveMutantStack);
    deque_stack_ = interactiveMutantStack.deque_stack_;
    list_stack_ = interactiveMutantStack.list_stack_;
    vector_stack_ = interactiveMutantStack.vector_stack_;
  }
  return *this;
}

void   InteractiveMutantStack::push(int element)
{
  deque_stack_.push(element);
  list_stack_.push(element);
  vector_stack_.push(element);
}

void   InteractiveMutantStack::pop()
{
  if (deque_stack_.empty() || list_stack_.empty() || vector_stack_.empty())
    return;
  deque_stack_.pop();
  list_stack_.pop();
  vector_stack_.pop();
}

bool   InteractiveMutantStack::empty() const
{
  return deque_stack_.empty() && list_stack_.empty() && vector_stack_.empty();
}

void  InteractiveMutantStack::print() const
{
  std::cout << "deque stack : ";
  for (MutantStack<int>::const_iterator it = deque_stack_.begin(); it != deque_stack_.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;

  std::cout << "list stack  : ";
  for (MutantStack<int, std::list<int> >::const_iterator it = list_stack_.begin(); it != list_stack_.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;

  std::cout << "vector stack: ";
  for (MutantStack<int, std::vector<int> >::const_iterator it = vector_stack_.begin(); it != vector_stack_.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}
