/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:07:14 by htsang            #+#    #+#             */
/*   Updated: 2023/09/14 19:31:11 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Vector.hpp"
#include "Fixed.hpp"

Point::Point() : x_(0), y_(0) {}

Point::Point(const float x, const float y) : x_(Fixed(x)), y_(Fixed(y)) {}

Point::Point(const Point& point) : x_(point.x_), y_(point.y_) {}

Point::~Point() {}

Vector  Point::to_vector(const Point& point) const
{
  return (Vector(point.x_ - x_, point.y_ - y_));
}
