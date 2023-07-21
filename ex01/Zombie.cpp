/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:21:40 by htsang            #+#    #+#             */
/*   Updated: 2023/07/18 22:36:29 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>
#include <string>

namespace my
{
  Zombie::Zombie()
  {
    this->name_ = "Zombie";
  }

  Zombie::Zombie(std::string name)
  {
    this->name_ = name;
  }

  Zombie::~Zombie() {
    std::cout << this->name_ << " is annihilated" << std::endl;
  }

  Zombie::Zombie(const Zombie &zombie)
  {
    *this = zombie;
  }

  Zombie& Zombie::operator=(const Zombie &zombie)
  {
    this->name_ = zombie.name_;
    return (*this);
  }

  void Zombie::setName(std::string name)
  {
    this->name_ = name;
  }

  void Zombie::announce() const
  {
    std::cout << this->name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
  }
} // namespace my
