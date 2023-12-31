/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/10/28 15:09:00 by htsang           ###   ########.fr       */
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
    std::string str(argv[1]);
    if (str.empty())
    {
      std::cout << "Usage: ./convert [string]" << std::endl;
      return EXIT_FAILURE;
    }
    ScalarConverter::convert(str);
    return EXIT_SUCCESS;
  }
  else
  {
    std::cerr << "Usage: " << argv[0] << " [scalar value]" << std::endl;
    return EXIT_FAILURE;
  }
}
