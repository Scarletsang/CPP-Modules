/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:08:06 by htsang            #+#    #+#             */
/*   Updated: 2023/09/14 19:31:29 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Vector.hpp"

static Fixed  orientation(Point const a, Point const b, Point const point)
{
  Vector  ab(a.to_vector(b));
  return ab.determinant(a.to_vector(point));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
  Fixed  o1 = orientation(a, b, point);
  Fixed  o2 = orientation(b, c, point);
  Fixed  o3 = orientation(c, a, point);
  return ((o1 >= 0 && o2 >= 0 && o3 >= 0) || (o1 <= 0 && o2 <= 0 && o3 <= 0));
}
