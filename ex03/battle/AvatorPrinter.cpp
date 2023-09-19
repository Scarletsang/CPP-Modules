/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AvatorPrinter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:04:53 by htsang            #+#    #+#             */
/*   Updated: 2023/09/19 14:54:22 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AvatorPrinter.hpp"

#include <iostream>
#include <iomanip>

AvatorPrinter::AvatorPrinter() : index_(0) {}

AvatorPrinter::AvatorPrinter(const AvatorPrinter& value) : index_(value.index_) {}

const AvatorPrinter& AvatorPrinter::operator=(const AvatorPrinter& value)
{
  index_ = value.index_;
  return *this;
}
