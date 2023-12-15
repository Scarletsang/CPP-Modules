/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:11:28 by htsang            #+#    #+#             */
/*   Updated: 2023/09/19 11:21:42 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap()
  : name_("without a name"),
    hit_points_(10),
    energy_points_(10),
    attack_damage_(0)
{
  std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
  : name_(name),
    hit_points_(10),
    energy_points_(10),
    attack_damage_(0)
{
  std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
  std::cout << "ClapTrap copy constructor called" << std::endl;
  *this = copy;
}

ClapTrap::~ClapTrap()
{
  std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
  std::cout << "ClapTrap assignation operator called" << std::endl;
  if (this != &copy) {
    this->name_ = copy.name_;
    this->hit_points_ = copy.hit_points_;
    this->energy_points_ = copy.energy_points_;
    this->attack_damage_ = copy.attack_damage_;
  }
  return *this;
}

bool  ClapTrap::isActive(const char *action) const
{
  if (hit_points_ == 0) {
    std::cout << "ClapTrap " << name_ << " is dead, he can't " << action << std::endl;
    return false;
  }
  else if (energy_points_ == 0) {
    std::cout << "ClapTrap " << name_ << " has no energy, he can't " << action << std::endl;
    return false;
  }
  return true;
}

void ClapTrap::attack(const std::string& target)
{
  if (isActive("attack"))
  {
    std::cout << "ClapTrap " << name_ << " attack " << target << ", causing "
              << attack_damage_ << " points of damage!" << std::endl;
    energy_points_--;
  }
}

void ClapTrap::beRepaired(unsigned int amount)
{
  if (isActive("be repaired"))
  {
    std::cout << "ClapTrap " << name_ << " is repaired for " << amount << " points!" << std::endl;
    hit_points_ += amount;
    energy_points_--;
  }
}

void ClapTrap::takeDamage(unsigned int amount)
{
  if (hit_points_ <= 0)
  {
    std::cout << "ClapTrap " << name_ << " is already dead, he can't take damage" << std::endl;
    return ;
  }
  std::cout << "ClapTrap " << name_ << " take " << amount << " points of damage!" << std::endl;
  hit_points_ -= amount;
  if (hit_points_ < 0)
    hit_points_ = 0;
}

std::string  ClapTrap::getName() const
{
  return name_;
}

int  ClapTrap::getHitPoints() const
{
  return hit_points_;
}

int  ClapTrap::getEnergyPoints() const
{
  return energy_points_;
}

int  ClapTrap::getAttackDamage() const
{
  return attack_damage_;
}
