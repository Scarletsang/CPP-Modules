/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 22:20:14 by htsang            #+#    #+#             */
/*   Updated: 2023/09/16 22:53:18 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

#include <iostream>

Ice::Ice()
  : AMateria("ice") {}

Ice::Ice(const Ice &copy)
  : AMateria(copy) {}

Ice::~Ice() {}

Ice &Ice::operator=(const Ice &ice)
{
  if (this == &ice)
    return (*this);
  AMateria::operator=(ice);
  return (*this);
}

AMateria* Ice::clone() const
{
  return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
  std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
