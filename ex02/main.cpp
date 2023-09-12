/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 21:30:49 by htsang            #+#    #+#             */
/*   Updated: 2023/09/12 19:34:57 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cstdlib>
#include <cstring>

#include <iostream>
#include <iomanip>
#include <string>

namespace printer
{
  template <typename T>
  void  Bitfield(T value)
  {
    unsigned char* bytes = reinterpret_cast<unsigned char*>(&value);
    for (int i = sizeof(T) - 1; i >= 0; i--)
    {
      for (int j = 7; j >= 0; j--)
      {
        std::cout << ((bytes[i] >> j) & 1);
      }
    }
    std::cout << std::endl;
  }
}

namespace my
{
  void  TestFromSubject()
  {
    Fixed       a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed const c( Fixed( 10.05f ) / Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << c << std::endl;
  }

  void  InteractivePrompt()
  {
    std::cout << "Enter a number as integer or float: ";
  }

  void  InteractiveErrorPrompt()
  {
    std::cout << "Invalid input. Please try again: ";
  }

  int  InteractiveEvaluate(std::string &input)
  {
    Fixed                       n(4);

    (void)input;
    std::cout << "n is printed as " << n << std::endl;
    std::cout << "n is " << n.toInt() << " as integer" << std::endl;
    std::cout << "n is " << n.toFloat() << " as float" << std::endl;
    printer::Bitfield(n.getRawBits());
    return EXIT_SUCCESS;
  }
}

int main(int argc, char const **argv)
{
  if (argc == 1)
  {
    my::TestFromSubject();
  }
  else if ((argc == 2) && (strcmp(argv[1], "-i") == 0))
  {
    std::string input;

    std::cout << "* tips * type 'exit' to exit this interactive session" << std::endl;
    my::InteractivePrompt();
    std::getline(std::cin, input);
    while (std::cin.good())
    {
      if (input.compare("exit") == 0)
        break ;
      if (my::InteractiveEvaluate(input))
      {
        my::InteractiveErrorPrompt();
      }
      else
      {
        my::InteractivePrompt();
      }
      std::getline(std::cin, input);
    }
  }
  else
  {
    std::cerr << "Usage: " << argv[0] << " [-i]" << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
