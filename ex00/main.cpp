/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/10/29 23:00:59 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include <iostream>
#include <string>

#include "InteractivePrompt.hpp"
#include "whatever.hpp"
#include "Fixed.hpp"

namespace parser
{
  int Int(std::string& input)
  {
    return std::atoi(input.c_str());
  }

  Fixed FixedNumber(std::string& input)
  {
    return Fixed(static_cast<float>(std::strtod(input.c_str(), NULL)));
  }
} // namespace parser

namespace interactive
{
  struct States
  {};  

  int MinAction(std::string input, struct States& states)
  {
    (void)input;
    (void)states;
    return EXIT_SUCCESS;
  }

  int MaxAction(std::string input, struct States& states)
  {
    (void)input;
    (void)states;
    return EXIT_SUCCESS;
  }

  int SwapAction(std::string input, struct States& states)
  {
    (void)input;
    (void)states;
    return EXIT_SUCCESS;
  }

  int Exit(std::string input, struct States& states)
  {
    (void)input;
    (void)states;
    return EXIT_FAILURE;
  }

  int Run()
  {
    struct States                     states;
    InteractivePrompt<struct States>  prompt;

    prompt.setPrompt("Enter a number");
    prompt.setReprompt("Invalid input. Try again: ");
    prompt.registerAction("min", MinAction);
    prompt.registerAction("max", MaxAction);
    prompt.registerAction("swap", SwapAction);
    prompt.registerAction("exit", Exit);
    prompt.shell(states);
    return EXIT_SUCCESS;
  }
} // namespace interactive

namespace noninteractive
{
  int Run()
  {
    int a = 2;
    int b = 3;

    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return EXIT_SUCCESS;
  }
} // namespace noninteractive

int main(int argc, const char** argv)
{
  if (argc == 1)
    return noninteractive::Run();
  else if (argc == 2 && std::string(argv[1]) == "-i")
    return interactive::Run();
  else
  {
    std::cerr << "Usage: " << argv[0] << " [-i]" << std::endl;
    return EXIT_FAILURE;
  }
}
