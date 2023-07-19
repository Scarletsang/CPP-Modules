/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 03:23:20 by htsang            #+#    #+#             */
/*   Updated: 2023/07/19 11:01:52 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

#include <string>
#include <iostream>

#include "Weapon.hpp"

HumanA& HumanA::operator=(const HumanA& human_a)
{
  if (this != &human_a)
  {
    this->name_ = human_a.name_;
    this->weapon_ = human_a.weapon_;
  }
  return (*this);
}

void  HumanA::attack() const
{
  std::cout << this->name_ << " attacks with their " << this->weapon_.getType() << std::endl;
}
