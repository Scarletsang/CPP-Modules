/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:56:37 by htsang            #+#    #+#             */
/*   Updated: 2023/09/15 20:02:45 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>
#include <string>

Brain::Brain()
{
  std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
  std::cout << "Brain copy constructor called" << std::endl;
  for (int i = 0; i < 100; i++)
      this->ideas[i] = copy.ideas[i];
}

Brain::~Brain()
{
  std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &copy)
{
  std::cout << "Brain assignation operator called" << std::endl;
  if (this != &copy)
  {
    for (int i = 0; i < 100; i++)
      this->ideas[i] = copy.ideas[i];
  }
  return (*this);
}

std::string Brain::getIdea(int index) const
{
  return (this->ideas[index]);
}

void Brain::setIdea(int index, std::string idea)
{
  this->ideas[index] = idea;
}
