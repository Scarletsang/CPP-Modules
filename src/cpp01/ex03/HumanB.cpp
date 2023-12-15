/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:51:49 by htsang            #+#    #+#             */
/*   Updated: 2023/07/19 11:07:10 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

#include <string>
#include <iostream>

#include "Weapon.hpp"

const HumanB& HumanB::operator=(const HumanB& human)
{
  if (this != &human)
  {
    this->name_ = human.name_;
    this->weapon_ = human.weapon_;
  }
  return *this;
}

void  HumanB::setWeapon(Weapon& weapon)
{
  weapon_ = &weapon;
}

void  HumanB::attack() const
{
  if (weapon_)
    std::cout << name_ << " attacks with their " << weapon_->getType() << std::endl;
  else
    std::cout << name_ << " attacks with their bare hands" << std::endl;
}
