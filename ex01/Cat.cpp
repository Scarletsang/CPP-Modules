/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:42:57 by htsang            #+#    #+#             */
/*   Updated: 2023/09/15 20:09:27 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

Cat::Cat() : Animal("Cat"), brain_(new Brain())
{
  std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy), brain_(copy.brain_)
{
  std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
  delete brain_;
  std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat) // copy assignment operator
{
  std::cout << "Cat assignation operator called" << std::endl;
  if (this != &cat)
  {
    Animal::operator=(cat);
    brain_ = cat.brain_;
  }
  return (*this);
}

void Cat::makeSound() const
{
  std::cout << "Cat make sound" << std::endl;
}
