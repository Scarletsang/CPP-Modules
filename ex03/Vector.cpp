/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:11:49 by htsang            #+#    #+#             */
/*   Updated: 2023/09/14 19:31:04 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"

Vector::Vector() : x_(0), y_(0) {}

Vector::Vector(const float x, const float y) : x_(Fixed(x)), y_(Fixed(y)) {}

Vector::Vector(const Fixed x, const Fixed y) : x_(x), y_(y) {}

Vector::Vector(const Vector& vector) : x_(vector.x_), y_(vector.y_) {}

Vector::~Vector() {}

Fixed Vector::determinant(const Vector& vector) const
{
  return (x_ * vector.y_ - (y_ * vector.x_));
}
