/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:42:57 by htsang            #+#    #+#             */
/*   Updated: 2023/09/21 10:41:53 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

Cat::Cat() : Animal("Cat"), brain_(new Brain())
{
  std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy), brain_(new Brain(*copy.brain_))
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
  std::cout << "Cat assignment operator called" << std::endl;
  if (this != &cat)
  {
    Animal::operator=(cat);
    brain_ = cat.brain_;
  }
  return (*this);
}

void Cat::makeSound() const
{
  std::cout << "Meow" << std::endl;
}
