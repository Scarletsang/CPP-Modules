/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:09:19 by htsang            #+#    #+#             */
/*   Updated: 2023/09/14 19:19:55 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Vector
{
  public:
    Vector();
    Vector(const Vector& vector);
    Vector(const float x, const float y);
    Vector(const Fixed x, const Fixed y);
    ~Vector();

    Fixed determinant(const Vector& vector) const;

  private:
    const Fixed x_;
    const Fixed y_;
    Vector& operator=(const Vector& vector);
};
