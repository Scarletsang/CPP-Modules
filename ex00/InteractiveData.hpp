/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InteractiveData.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:19:43 by htsang            #+#    #+#             */
/*   Updated: 2023/11/28 00:03:00 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <vector>
#include <list>
#include <deque>

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
};

/////////////////////////////////////////////////////
////////////   template implementation   ////////////
/////////////////////////////////////////////////////

template <typename T>
void  InteractiveData::generate(T& container, int size);
{
  container.clear();
  std::srand(std::time(NULL));
  for (int i = 0; i < size; i++)
    container.push_back(std::rand() % 100);
}
