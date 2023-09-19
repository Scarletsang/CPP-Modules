/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragAvatorPrinter.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:05:38 by htsang            #+#    #+#             */
/*   Updated: 2023/09/19 14:53:53 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragAvatorPrinter.hpp"

#include <cstdlib>

#include <iostream>
#include <iomanip>

FragAvatorPrinter::FragAvatorPrinter() : AvatorPrinter() {}

FragAvatorPrinter::FragAvatorPrinter(const FragAvatorPrinter& value) : AvatorPrinter(value) {}

FragAvatorPrinter::~FragAvatorPrinter() {}

const FragAvatorPrinter& FragAvatorPrinter::operator=(const FragAvatorPrinter& value)
{
  AvatorPrinter::operator=(value);
  return *this;
}

int   FragAvatorPrinter::next()
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

bool  FragAvatorPrinter::isEnd() const
{
  return index_ >= 5;
}
