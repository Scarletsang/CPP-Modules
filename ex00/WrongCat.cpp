/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:42:57 by htsang            #+#    #+#             */
/*   Updated: 2023/09/15 19:47:01 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
  std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
  std::cout << "WrongCat copy constructor called" << std::endl;
  *this = copy;
}

WrongCat::~WrongCat()
{
  std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &op)
{
  std::cout << "WrongCat assignation operator called" << std::endl;
  if (this != &op)
    this->type = op.type;
  return (*this);
}

void WrongCat::makeSound() const
{
  std::cout << "WrongCat make sound" << std::endl;
}
