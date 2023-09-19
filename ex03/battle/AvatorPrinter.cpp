/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AvatorPrinter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:31:49 by htsang            #+#    #+#             */
/*   Updated: 2023/09/19 22:24:07 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AvatorPrinter.hpp"
#include "Generator.hpp"

#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "../ClapTrap.hpp"

AvatorPrinter::AvatorPrinter()
  : Generator(), avator_type_(kClapTrap) {}

AvatorPrinter::AvatorPrinter(Type avator_type)
  : Generator(), avator_type_(avator_type) {}

AvatorPrinter::AvatorPrinter(const AvatorPrinter& value)
  : Generator(), avator_type_(value.avator_type_) {}

AvatorPrinter::~AvatorPrinter() {}

const AvatorPrinter& AvatorPrinter::operator=(const AvatorPrinter& value)
{
  Generator::operator=(value);
  return *this;
}

bool  AvatorPrinter::isEnd() const
{
  return index_ >= 5;
}

int   AvatorPrinter::next()
{
  if (avator_type_ == kClapTrap)
    return clapTrapNext();
  else if (avator_type_ == kScavTrap)
    return scavTrapNext();
  else if (avator_type_ == kFragTrap)
    return fragTrapNext();
  else if (avator_type_ == kDiamondTrap)
    return diamondTrapNext();
  return 0;
}

int   AvatorPrinter::clapTrapNext()
{
  if (index_ == 0)
    std::cout << std::setw(3) << " " << ".-----.  " << std::setw(4) << " ";
  else if (index_ == 1)
    std::cout << std::setw(3) << " " << " / o o \\ " << std::setw(4) << " ";
  else if (index_ == 2)
    std::cout << std::setw(3) << " " << "|   ∆   |" << std::setw(4) << " ";
  else if (index_ == 3)
    std::cout << std::setw(3) << " " << "|   ~   |" << std::setw(4) << " ";
  else if (index_ == 4)
    std::cout << std::setw(3) << " " << " \\_____/ " << std::setw(4) << " ";
  else if (index_ == 5)
    std::cout << std::setw(3) << " " << "  }      " << std::setw(4) << " ";
  index_++;
  return EXIT_SUCCESS;
}

int   AvatorPrinter::scavTrapNext()
{
  if (index_ == 0)
    std::cout << std::setw(3) << " " << ".-----.  " << std::setw(4) << " ";
  else if (index_ == 1)
    std::cout << std::setw(3) << " " << " / - x \\ " << std::setw(4) << " ";
  else if (index_ == 2)
    std::cout << std::setw(3) << " " << "|  (^)  |" << std::setw(4) << " ";
  else if (index_ == 3)
    std::cout << std::setw(3) << " " << "|   U   |" << std::setw(4) << " ";
  else if (index_ == 4)
    std::cout << std::setw(3) << " " << " \\_____/ " << std::setw(4) << " ";
  else if (index_ == 5)
    std::cout << std::setw(3) << " " << "  }      " << std::setw(4) << " ";
  index_++;
  return EXIT_SUCCESS;
}

int   AvatorPrinter::fragTrapNext()
{
  if (index_ == 0)
    std::cout << std::setw(3) << " " << ".-----.  " << std::setw(4) << " ";
  else if (index_ == 1)
    std::cout << std::setw(3) << " " << " / $ $ \\ " << std::setw(4) << " ";
  else if (index_ == 2)
    std::cout << std::setw(3) << " " << "|   ∆   |" << std::setw(4) << " ";
  else if (index_ == 3)
    std::cout << std::setw(3) << " " << "|  /w\\  |" << std::setw(4) << " ";
  else if (index_ == 4)
    std::cout << std::setw(3) << " " << " \\_____/ " << std::setw(4) << " ";
  else if (index_ == 5)
    std::cout << std::setw(3) << " " << "  }      " << std::setw(4) << " ";
  index_++;
  return EXIT_SUCCESS;
}

int   AvatorPrinter::diamondTrapNext()
{
  if (index_ == 0)
    std::cout << std::setw(3) << " " << "    ^    " << std::setw(4) << " ";
  else if (index_ == 1)
    std::cout << std::setw(3) << " " << " / $ $ \\ " << std::setw(4) << " ";
  else if (index_ == 2)
    std::cout << std::setw(3) << " " << "<   ∆   >" << std::setw(4) << " ";
  else if (index_ == 3)
    std::cout << std::setw(3) << " " << " \\ /w\\ / " << std::setw(4) << " ";
  else if (index_ == 4)
    std::cout << std::setw(3) << " " << "   \\  /  " << std::setw(4) << " ";
  else if (index_ == 5)
    std::cout << std::setw(3) << " " << "    V    " << std::setw(4) << " ";
  index_++;
  return EXIT_SUCCESS;
}
