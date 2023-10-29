/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:20:41 by htsang            #+#    #+#             */
/*   Updated: 2023/10/28 19:22:03 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : location_x(0), location_y(0) {}

Data::Data(int x, int y) : location_x(x), location_y(y) {}

Data::Data(Data const& src) : location_x(src.location_x), location_y(src.location_y) {}

Data::~Data() {}

Data& Data::operator=(Data const& rhs)
{
  if (this != &rhs)
  {
    this->location_x = rhs.location_x;
    this->location_y = rhs.location_y;
  }
  return (*this);
}

int Data::x() const { return this->location_x; }

int Data::y() const { return this->location_y; }

std::ostream& operator<<(std::ostream& os, Data const& rhs)
{
  os << "Data(" << rhs.x() << ", " << rhs.y() << ")";
  return (os);
}
