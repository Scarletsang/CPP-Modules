/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:41:28 by htsang            #+#    #+#             */
/*   Updated: 2023/09/15 19:46:02 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
  std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
  std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
  std::cout << "WrongAnimal copy constructor called" << std::endl;
  *this = copy;
}

WrongAnimal::~WrongAnimal()
{
  std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &op)
{
  std::cout << "WrongAnimal assignation operator called" << std::endl;
  if (this != &op)
    this->type = op.type;
  return (*this);
}

std::string WrongAnimal::getType() const
{
  return (this->type);
}

void WrongAnimal::makeSound() const
{
  std::cout << "WrongAnimal make sound" << std::endl;
}
