/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:27:40 by htsang            #+#    #+#             */
/*   Updated: 2023/09/22 21:57:10 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap()
  : ClapTrap(), ScavTrap(), FragTrap(), name_(ClapTrap::name_ + "_clap_name")
{
  std::cout << "DiamondTrap Default constructor called" << std::endl;
  hit_points_ = FragTrap::kDefaultHitPoints;
  energy_points_ = ScavTrap::kDefaultEnergyPoints;
  attack_damage_ = FragTrap::kDefaultAttackDamage;
}

DiamondTrap::DiamondTrap(std::string name)
  : ClapTrap(name + "_clap_name"),
    ScavTrap(name),
    FragTrap(name),
    name_(name)
{
  std::cout << "DiamondTrap constructor called" << std::endl;
  hit_points_ = FragTrap::kDefaultHitPoints;
  energy_points_ = ScavTrap::kDefaultEnergyPoints;
  attack_damage_ = FragTrap::kDefaultAttackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy)
  : ClapTrap(copy),
    ScavTrap(copy),
    FragTrap(copy),
    name_(copy.name_)
{
  std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
  std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy)
{
  std::cout << "DiamondTrap assignation operator called" << std::endl;
  if (this != &copy)
  {
    ClapTrap::operator=(copy);
    name_ = copy.name_;
  }
  return *this;
}

void  DiamondTrap::attack(const std::string& target)
{
  ScavTrap::attack(target);
}

void  DiamondTrap::whoAmI()
{
  std::cout << "DiamondTrap name: " << name_ << std::endl;
  std::cout << "ClapTrap name: " << ClapTrap::name_ << std::endl;
}
