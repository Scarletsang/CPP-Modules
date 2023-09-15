/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:49:10 by htsang            #+#    #+#             */
/*   Updated: 2023/09/15 19:05:10 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap()
  :  ClapTrap(ScavTrap::kDefaultHitPoints,
              ScavTrap::kDefaultEnergyPoints,
              ScavTrap::kDefaultAttackDamage)
{
  std::cout << "Scavtrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
  :  ClapTrap(name,
              ScavTrap::kDefaultHitPoints,
              ScavTrap::kDefaultEnergyPoints,
              ScavTrap::kDefaultAttackDamage)
{
  std::cout << "Scavtrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy)
{
  std::cout << "Scavtrap copy constructor called" << std::endl;
  *this = copy;
}

ScavTrap::~ScavTrap()
{
  std::cout << "Scavtrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
  std::cout << "Scavtrap assignation operator called" << std::endl;
  if (this != &copy)
  {
    ClapTrap::operator=(copy);
  }
  return *this;
}

void  ScavTrap::attack(const std::string& target)
{
  if (isActive("attack"))
    std::cout << "Scavtrap " << name_ << " attack " << target << ", causing " << attack_damage_ << " points of damage!" << std::endl;
}

void  ScavTrap::guardGate()
{
  if (isActive("guard gate"))
    std::cout << "Scavtrap " << name_ << " has entered in Gate keeper mode" << std::endl;
}
