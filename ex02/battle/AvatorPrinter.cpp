/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AvatorPrinter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:05:38 by htsang            #+#    #+#             */
/*   Updated: 2023/09/19 13:33:19 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AvatorPrinter.hpp"

#include <cstdlib>

#include <iostream>
#include <iomanip>

AvatorPrinter::AvatorPrinter() : Generator() {}

AvatorPrinter::AvatorPrinter(const AvatorPrinter& value) : Generator(value) {}

AvatorPrinter::~AvatorPrinter() {}

const AvatorPrinter& AvatorPrinter::operator=(const AvatorPrinter& value)
{
  Generator::operator=(value);
  return *this;
}

int   AvatorPrinter::next()
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

bool  AvatorPrinter::isEnd() const
{
  return index_ >= 5;
}
