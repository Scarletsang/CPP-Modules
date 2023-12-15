/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:04:52 by htsang            #+#    #+#             */
/*   Updated: 2023/09/14 18:57:16 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"
#include "Vector.hpp"

class Point
{
  public:
    Point();
    Point(const Point& point);
    Point(const float x, const float y);
    ~Point();

    Vector  to_vector(const Point& point) const;

  private:
    const Fixed x_;
    const Fixed y_;

    Point& operator=(const Point& point);
};
