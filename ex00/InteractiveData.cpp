/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InteractiveData.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 23:30:22 by htsang            #+#    #+#             */
/*   Updated: 2023/11/28 00:53:01 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InteractiveData.hpp"

InteractiveData::InteractiveData()
  : vector_(), list_(), deque_() {}

InteractiveData::InteractiveData(const InteractiveData& interactivedata)
  : vector_(interactivedata.vector_), list_(interactivedata.list_), deque_(interactivedata.deque_) {}

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

  std::cout << "list: ";
  for (std::list<int>::const_iterator it = list_.begin(); it != list_.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;

  std::cout << "deque: ";
  for (std::deque<int>::const_iterator it = deque_.begin(); it != deque_.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;
}

// TODO
void  InteractiveData::print_element(int value) const
{
  std::cout << "vector: ";
  try
  {
    std::cout << easyfind(vector_, value) << std::endl;
  }
  catch (std::exception& e)
  {
    std::cout << e.what() << std::endl;
  }

  std::cout << "list: ";
  try
  {
    std::cout << easyfind(list_, value) << std::endl;
  }
  catch (std::exception& e)
  {
    std::cout << e.what() << std::endl;
  }

  std::cout << "deque: ";
  try
  {
    std::cout << easyfind(deque_, value) << std::endl;
  }
  catch (std::exception& e)
  {
    std::cout << e.what() << std::endl;
  }
}