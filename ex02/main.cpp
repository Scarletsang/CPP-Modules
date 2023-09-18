/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 21:30:49 by htsang            #+#    #+#             */
/*   Updated: 2023/09/18 19:07:32 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cstdlib>
#include <cstring>

#include <iostream>
#include <iomanip>
#include <string>

namespace test
{
  int  ParseNumber(std::string input, Fixed &n)
  {
    std::string::iterator it  = input.begin();
    float sign                = 1.0f;
    float number              = 0.f;

    if (*it == '-')
    {
      it++;
      sign = -1.0f;
    }
    if (!std::isdigit(*it))
      return 0;
    while ((it != input.end()) && std::isdigit(*it))
    {
      number = number * 10.f + (*it - '0');
      it++;
    }
    if (*it == '.')
    {
      float decimal = 0.f;
      float power   = 10.0f;

      it++;
      while ((it != input.end()) && std::isdigit(*it))
      {
        decimal += ((*it - '0') / power);
        power *= 10.0f;
        it++;
      }
      number += decimal;
    }
    if (Fixed::is_convertable(number * sign) == false)
      return 0;
    n = Fixed(number * sign);
    return it - input.begin();
  }

  int ParseExpression(std::string input, Fixed &n)
  {
    Fixed a;
    Fixed b;
    char  op;
    int   pos = test::ParseNumber(input, a);

    while (input[pos] == ' ')
      pos++;
    op = input[pos];
    if ((op != '+') && (op != '-') && (op != '*') && (op != '/'))
      return 0;
    pos++;
    while (input[pos] == ' ')
      pos++;
    int pos2 = test::ParseNumber(input.substr(pos), b);
    if (pos2 == 0)
      return 0;
    if (op == '+')
      n = a + b;
    else if (op == '-')
      n = a - b;
    else if (op == '*')
      n = a * b;
    else if (op == '/')
      n = a / b;
    return pos + pos2;
  }
} // namespace test

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
} // namespace printer

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
    Fixed n;
  
    if (test::ParseExpression(input, n) == 0)
      return EXIT_FAILURE;
    std::cout << "n is printed as " << n << std::endl;
    std::cout << "n is " << n.toInt() << " as integer" << std::endl;
    std::cout << "n is " << n.toFloat() << " as float" << std::endl;
    printer::Bitfield(n.getRawBits());
    return EXIT_SUCCESS;
  }
} // namespace my

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
