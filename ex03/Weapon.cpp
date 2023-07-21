/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 03:07:04 by htsang            #+#    #+#             */
/*   Updated: 2023/07/19 11:02:21 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

#include <string>

Weapon::Weapon(const Weapon& weapon)
{
  *this = weapon;
}

const Weapon& Weapon::operator=(const Weapon& weapon)
{
  if (this != &weapon)
  {
    this->type_ = weapon.type_;
  }
  return (*this);
}

const std::string& Weapon::getType() const
{
  return (this->type_);
}

void Weapon::setType(std::string type)
{
  this->type_ = type;
}
