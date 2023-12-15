/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InteractiveData.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 23:30:22 by htsang            #+#    #+#             */
/*   Updated: 2023/11/28 15:53:11 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InteractiveData.hpp"

#include <iterator>
#include <iostream>

InteractiveData::InteractiveData()
  : InteractivePrompt::Data(),
    vector_(), list_(), deque_() {}

InteractiveData::InteractiveData(const InteractiveData& interactivedata)
  : InteractivePrompt::Data(),
    vector_(interactivedata.vector_), list_(interactivedata.list_), deque_(interactivedata.deque_) {}

InteractiveData::~InteractiveData() {}

const InteractiveData& InteractiveData::operator=(const InteractiveData& interactivedata)
{
  if (this == &interactivedata)
    return *this;
  vector_ = interactivedata.vector_;
  list_ = interactivedata.list_;
  deque_ = interactivedata.deque_;
  return *this;
}

void  InteractiveData::generate(int size)
{
  generate(vector_, size);
  generate(list_, size);
  generate(deque_, size);
}

void  InteractiveData::print() const
{
  std::cout << "vector: ";
  for (std::vector<int>::const_iterator it = vector_.begin(); it != vector_.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;

  std::cout << "list:   ";
  for (std::list<int>::const_iterator it = list_.begin(); it != list_.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;

  std::cout << "deque:  ";
  for (std::deque<int>::const_iterator it = deque_.begin(); it != deque_.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;
}

// TODO
void  InteractiveData::print_element(int value) const
{
  std::cout << "vector: ";
  print_element(vector_, value);

  std::cout << "list:   ";
  print_element(list_, value);

  std::cout << "deque:  ";
  print_element(deque_, value);
}
