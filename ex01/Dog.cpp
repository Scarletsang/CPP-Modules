/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:44:27 by htsang            #+#    #+#             */
/*   Updated: 2023/09/15 20:09:03 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal("Dog"), brain_(new Brain())
{
  std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy), brain_(copy.brain_)
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
  std::cout << "Dog make sound" << std::endl;
}
