/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StatusPrinter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:08:57 by htsang            #+#    #+#             */
/*   Updated: 2023/09/19 20:29:06 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StatusPrinter.hpp"

#include <cstdlib>

#include <iomanip>

StatusPrinter::StatusPrinter(ClapTrap &claptrap)
  : Generator(), claptrap_(claptrap) {}

StatusPrinter::StatusPrinter(const StatusPrinter& value)
  : Generator(), claptrap_(value.claptrap_) {}

StatusPrinter::~StatusPrinter() {}

const StatusPrinter& StatusPrinter::operator=(const StatusPrinter& value)
{
  claptrap_ = value.claptrap_;
  return *this;
}

int   StatusPrinter::next()
{
  if (index_ == 0)
    std::cout << "Name: " << std::setw(10) << claptrap_.getName();
  else if (index_ == 1)
    std::cout << "HP:   " << std::setw(10) << claptrap_.getHitPoints();
  else if (index_ == 2)
    std::cout << "EP:   " << std::setw(10) << claptrap_.getEnergyPoints();
  else if (index_ == 3)
    std::cout << "AD:   " << std::setw(10) << claptrap_.getAttackDamage();
  else
    return 0;
  index_++;
  return EXIT_SUCCESS;
}

bool  StatusPrinter::isEnd() const
{
  return index_ >= 4;
}
