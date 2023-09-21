/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:44:27 by htsang            #+#    #+#             */
/*   Updated: 2023/09/21 10:42:21 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal("Dog")
{
  std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
  std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
  std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &op)
{
  std::cout << "Dog assignment operator called" << std::endl;
  if (this != &op)
    this->type = op.type;
  return (*this);
}

void Dog::makeSound() const
{
  std::cout << "bark" << std::endl;
}
