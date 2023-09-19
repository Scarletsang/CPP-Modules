/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:18:54 by htsang            #+#    #+#             */
/*   Updated: 2023/09/19 22:24:19 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap()
  : ClapTrap(FragTrap::kDefaultHitPoints,
             FragTrap::kDefaultEnergyPoints,
             FragTrap::kDefaultAttackDamage)
{
  std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
  : ClapTrap(name,
             FragTrap::kDefaultHitPoints,
             FragTrap::kDefaultEnergyPoints,
             FragTrap::kDefaultAttackDamage)
{
  std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
  std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
  std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy)
{
  std::cout << "FragTrap assignation operator called" << std::endl;
  if (this != &copy)
  {
    ClapTrap::operator=(copy);
  }
  return *this;
}

void  FragTrap::highFivesGuys()
{
  if (isActive("high fives guys"))
  {
    std::cout << "Fragtrap " << name_ << " high fives guys" << std::endl;
    energy_points_--;
  }
}
