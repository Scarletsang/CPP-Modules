/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:42:57 by htsang            #+#    #+#             */
/*   Updated: 2023/09/15 20:02:55 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

Cat::Cat() : Animal("Cat")
{
  std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &copy)
{
  std::cout << "Cat copy constructor called" << std::endl;
  *this = copy;
}

Cat::~Cat()
{
  std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
  std::cout << "Cat assignation operator called" << std::endl;
  if (this != &copy)
    this->type = copy.type;
  return (*this);
}

void Cat::makeSound() const
{
  std::cout << "Cat make sound" << std::endl;
}
