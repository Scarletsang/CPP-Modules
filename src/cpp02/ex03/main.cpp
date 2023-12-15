/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:59:41 by htsang            #+#    #+#             */
/*   Updated: 2023/09/14 19:26:35 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include "Vector.hpp"
#include <stdlib.h>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(int argc, const char **argv)
{
  if (argc != 9)
    return EXIT_FAILURE;
  float coordinates[8];

  for (int i = 0; i < 8; i++)
  {
    coordinates[i] = strtof(argv[i + 1], NULL);
  }
  Point a(coordinates[0], coordinates[1]);
  Point b(coordinates[2], coordinates[3]);
  Point c(coordinates[4], coordinates[5]);
  Point point(coordinates[6], coordinates[7]);
  if (bsp(a, b, c, point))
    std::cout << "Point is inside the triangle" << std::endl;
  else
    std::cout << "Point is outside the triangle" << std::endl;
  return EXIT_SUCCESS;
}
