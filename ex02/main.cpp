/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 21:30:49 by htsang            #+#    #+#             */
/*   Updated: 2023/08/16 19:11:16 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cstdlib>
#include <cstring>

#include <iostream>
#include <iomanip>
#include <string>

namespace parser
{
  bool  Match(std::string::const_iterator &it, \
              std::string::const_iterator end, \
              const char *match_target)
  {
    while ((it != end) && *match_target)
    {
      if (*it != *match_target)
        return false;
      match_target++;
      it++;
    }
    return true;
  }

  bool  FixedNumber(std::string::const_iterator &it, \
                    std::string::const_iterator end, \
                    Fixed &n)
  {
    std::string::const_iterator copy(it);
    float                       sign   = 1.0f;
    float                       number = 0.f;

    if (*copy == '-')
    {
      copy++;
      sign = -1.0f;
    }
    if (!std::isdigit(*copy))
      return false;
    while ((copy != end) && std::isdigit(*copy))
    {
      number = number * 10.f + (*copy - '0');
      copy++;
    }
    if (*copy == '.')
    {
      float decimal = 0.f;
      float power   = 10.0f;

      copy++;
      while ((copy != end) && std::isdigit(*copy))
      {
        decimal += ((*copy - '0') / power);
        power *= 10.0f;
        copy++;
      }
      number += decimal;
    }
    n = Fixed(number * sign);
    it = copy;
    return true;
  }

  bool  FixedNumberModified(std::string::const_iterator &it, \
                            std::string::const_iterator end, \
                            Fixed &n)
  {
    enum Modifier { kIncrement, kDecrement, kNone };
    std::string::const_iterator copy(it);
    Modifier                    suffix = kNone;
    
    if (Match(copy, end, "++"))
      suffix = kIncrement;
    else if (Match(copy, end, "--"))
      suffix = kDecrement;
    if (!FixedNumber(copy, end, n))
      return false;
    if (suffix == kIncrement)
      n++;
    else if (suffix == kDecrement)
      n--;
    else
    {
      if (Match(copy, end, "++"))
        n++;
      else if (Match(copy, end, "--"))
        n--;
    }
    it = copy;
    return true;
  }

  bool  Term(std::string::const_iterator &it, \
             std::string::const_iterator end, \
             Fixed &n)
  {
    std::string::const_iterator copy(it);

    if (!FixedNumber(copy, end, n))
      return false;
    while (copy != end)
    {
      Fixed n2;

      if (!FixedNumber(copy, end, n2))
        return true;
      if (*(copy - 1) == '*')
        n = n * n2;
      else
        n = n / n2;
    }
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
}

namespace my
{
  void  TestFromSubject()
  {
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);

    a = Fixed(1234.4321f);

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
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
    Fixed                       n;
    std::string::const_iterator it = input.begin();

    if (!parser::FixedNumber(it, input.end(), n))
      return EXIT_FAILURE;
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
