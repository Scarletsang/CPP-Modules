/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:37:02 by htsang            #+#    #+#             */
/*   Updated: 2023/09/15 20:39:33 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#include <string>
#include <iostream>

AMateria::AMateria() : type_("nothing") {}

AMateria::AMateria(std::string const & type) : type_(type) {}

AMateria::AMateria(const AMateria &copy)
{
  *this = copy;
}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &op)
{
  if (this != &op)
    this->type_ = op.type_;
  return (*this);
}

std::string const & AMateria::getType() const
{
  return type_;
}

void AMateria::use(ICharacter& target)
{
  std::cout << "* shoots nothing at " << target.getName() << " *" << std::endl;
}
