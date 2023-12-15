/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:40:40 by htsang            #+#    #+#             */
/*   Updated: 2023/09/20 17:48:38 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Vector.hpp"
#include "materias/AMateria.hpp"

#include <string>
#include <iostream>

Character::Character()
  : name_("no one"),
    ground_(Vector<AMateria *>(4))
{
  for (int i = 0; i < 4; i++)
  {
    inventory_[i] = NULL;
  }
}

Character::Character(std::string name)
  : name_(name), ground_(Vector<AMateria *>(4))
{
  for (size_t i = 0; i < 4; i++)
  {
    inventory_[i] = NULL;
  }
}

Character::Character(const Character &copy)
{
  reset();
  name_ = copy.name_;
  for (int i = 0; i < 4; i++)
  {
    inventory_[i] = copy.inventory_[i]->clone();
  }
}

Character::~Character()
{
  reset();
}

Character &Character::operator=(const Character &character)
{
  if (this == &character)
    return (*this);
  reset();
  name_ = character.name_;
  for (int i = 0; i < 4; i++)
  {
    inventory_[i] = character.inventory_[i]->clone();
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

void  Character::unequip(int idx)
{
  if (idx < 0 || idx > 3)
    return ;
  if (inventory_[idx])
  {
    ground_.push_back(inventory_[idx]);
    inventory_[idx] = NULL;
  }
}

void  Character::use(int idx, ICharacter& target)
{
  if (idx < 0 || idx > 3)
    return ;
  if (inventory_[idx])
  {
    inventory_[idx]->use(target);
    delete inventory_[idx];
    inventory_[idx] = NULL;
  }
}

void  Character::printInventory() const
{
  std::cout << "Inventory: ";
  for (int i = 0; i < 4; i++)
  {
    if (inventory_[i])
      std::cout << *inventory_[i];
    else
      std::cout << "empty";
    if (i < 3)
      std::cout << ", ";
  }
  std::cout << std::endl;
}

void  Character::printGround() const
{
  std::cout << "Ground: ";
  for (size_t i = 0; i < ground_.size(); i++)
  {
    if (ground_[i])
      std::cout << *ground_[i];
    else
      std::cout << "empty";
    if (i < (ground_.size() - 1))
      std::cout << ", ";
  }
  std::cout << std::endl;
}

void  Character::print() const
{
  std::cout << std::endl << "Character: " << name_ << std::endl;
  printInventory();
  printGround();
  std::cout << std::endl;
}

void  Character::reset()
{
  for (int i = 0; i < 4; i++)
  {
    if (inventory_[i])
      delete inventory_[i];
    inventory_[i] = NULL;
  }
  for (size_t i = 0; i < ground_.size(); i++)
  {
    delete ground_[i];
  }
  ground_.clear();
}
