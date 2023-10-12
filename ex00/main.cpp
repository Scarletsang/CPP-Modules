/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/10/12 19:30:17 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cstdlib>

#include <iostream>
#include <string>

int main(int argc, const char** argv)
{
  if (argc == 2)
  {
    ScalarConverter::convert(argv[1]);
    return EXIT_SUCCESS;
  }
  else
  {
    std::cerr << "Usage: " << argv[0] << " [scalar value]" << std::endl;
    return EXIT_FAILURE;
  }
}
