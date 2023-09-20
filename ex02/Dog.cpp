/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:44:27 by htsang            #+#    #+#             */
/*   Updated: 2023/09/20 21:38:19 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal("Dog"), brain_(new Brain())
{
  std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy), brain_(new Brain(*copy.brain_))
{
  std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
  delete brain_;
  std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
  std::cout << "Dog assignation operator called" << std::endl;
  if (this != &dog)
  {
    Animal::operator=(dog);
    brain_ = dog.brain_;
  }
  return (*this);
}

void Dog::makeSound() const
{
  std::cout << "Bark" << std::endl;
}
