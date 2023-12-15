/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 22:18:48 by htsang            #+#    #+#             */
/*   Updated: 2023/09/16 22:52:38 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

#include <iostream>

Cure::Cure()
  : AMateria("cure") {}

Cure::Cure(const Cure &copy)
  : AMateria(copy) {}

Cure::~Cure() {}

Cure &Cure::operator=(const Cure &cure)
{
  if (this == &cure)
    return (*this);
  AMateria::operator=(cure);
  return (*this);
}

AMateria* Cure::clone() const
{
  return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
