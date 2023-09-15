/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:40:40 by htsang            #+#    #+#             */
/*   Updated: 2023/09/15 20:44:03 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name_("no one") {}

Character::Character(std::string name)
  : name_(name) {}

Character::Character(const Character &copy)
{
  *this = copy;
}

Character::~Character()
{
  for (int i = 0; i < 4; i++)
  {
    if (inventory_[i])
      delete inventory_[i];
  }
}

Character &Character::operator=(const Character &op)
{
  if (this == &op)
    return (*this);
  name_ = op.name_;
  for (int i = 0; i < 4; i++)
  {
    if (inventory_[i])
      delete inventory_[i];
    inventory_[i] = op.inventory_[i]->clone();
  }
  return (*this);
}

std::string const & Character::getName() const
{
  return name_;
}

void Character::equip(AMateria* m)
{
  for (int i = 0; i < 4; i++)
  {
    if (!inventory_[i])
    {
      inventory_[i] = m;
      return ;
    }
  }
}
