/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InteractiveData.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:19:43 by htsang            #+#    #+#             */
/*   Updated: 2023/11/28 15:55:10 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ctime>

#include <string>
#include <vector>
#include <list>
#include <deque>
#include <iterator>
#include <utility>
#include <iostream>

#include "InteractivePrompt.hpp"
#include "easyfind.hpp"

class InteractiveData : public InteractivePrompt::Data
{
  public:
    InteractiveData();
    InteractiveData(const InteractiveData& interactivedata);
    virtual ~InteractiveData();
    const InteractiveData& operator=(const InteractiveData& interactivedata);

    void  generate(int size);
    void  print() const;
    void  print_element(int value) const;

  private:
    std::vector<int>  vector_;
    std::list<int>    list_;
    std::deque<int>   deque_;
  
    template <typename T>
    void  generate(T& container, int size);

    template <typename T>
    void  print_element(T& container, int value) const;
};

/////////////////////////////////////////////////////
////////////   template implementation   ////////////
/////////////////////////////////////////////////////

template <typename T>
void  InteractiveData::generate(T& container, int size)
{
  container.clear();
  std::srand(std::time(NULL));
  for (int i = 0; i < size; i++)
    container.push_back(std::rand() % 100);
}

template <typename T>
void  InteractiveData::print_element(T& container, int value) const
{
  std::pair<int, int> result = easyfind(container, value);
  if (result.second == -1)
    std::cout << "Element " << value << " not found in container" << std::endl;
  else
    std::cout << "Find result " << result.first << " at index " << result.second << std::endl;
}
