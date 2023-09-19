/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondAvatorPrinter.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:05:38 by htsang            #+#    #+#             */
/*   Updated: 2023/09/19 14:03:41 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondAvatorPrinter.hpp"

#include <cstdlib>

#include <iostream>
#include <iomanip>

DiamondAvatorPrinter::DiamondAvatorPrinter() : AvatorPrinter() {}

DiamondAvatorPrinter::DiamondAvatorPrinter(const DiamondAvatorPrinter& value) : AvatorPrinter(value) {}

DiamondAvatorPrinter::~DiamondAvatorPrinter() {}

const DiamondAvatorPrinter& DiamondAvatorPrinter::operator=(const DiamondAvatorPrinter& value)
{
  AvatorPrinter::operator=(value);
  return *this;
}

int   DiamondAvatorPrinter::next()
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

bool  DiamondAvatorPrinter::isEnd() const
{
  return index_ >= 5;
}
