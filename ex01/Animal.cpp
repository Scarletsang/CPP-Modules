/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:41:28 by htsang            #+#    #+#             */
/*   Updated: 2023/09/15 19:42:18 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <iostream>

Animal::Animal() : type("Animal")
{
  std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
  std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
  std::cout << "Animal copy constructor called" << std::endl;
  *this = copy;
}

Animal::~Animal()
{
  std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &op)
{
  std::cout << "Animal assignation operator called" << std::endl;
  if (this != &op)
    this->type = op.type;
  return (*this);
}

std::string Animal::getType() const
{
  return (this->type);
}

void Animal::makeSound() const
{
  std::cout << "Animal make sound" << std::endl;
}
