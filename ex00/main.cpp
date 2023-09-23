/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/09/24 00:57:05 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "interactive.hpp"

#include <cstdlib>

#include <iostream>
#include <string>

namespace interactive
{
  int RunIncrement(Bureaucrat* bureaucrat)
  {
    try
    {
      bureaucrat->incrementGrade();
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }
    return EXIT_SUCCESS;
  }

  int RunDecrement(Bureaucrat* bureaucrat)
  {
    try
    {
      bureaucrat->decrementGrade();
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }
    return EXIT_SUCCESS;
  }

  int Run()
  {
    std::string input;
    Bureaucrat* bureaucrat;

    if (parser::ParseUntilCorrect(input, bureaucrat))
      return EXIT_FAILURE;
    printer::InteractivePrompt();
    std::getline(std::cin, input);
    while (std::cin.good())
    {
      if (input == "+")
        RunIncrement(bureaucrat);
      else if (input == "-")
        RunDecrement(bureaucrat);
      else if (input == "exit")
      {
        delete bureaucrat;
        return EXIT_SUCCESS;
      }
      else
      {
        printer::InteractiveInvalidPrompt();
        std::getline(std::cin, input);
        continue ;
      }
      std::cout << *bureaucrat << std::endl;
      printer::InteractivePrompt();
      std::getline(std::cin, input);
    }
    delete bureaucrat;
    return EXIT_SUCCESS;
  }
} // namespace battle

namespace noninteractive
{
  int Run()
  {
    Bureaucrat bureaucrat;

    std::cout << bureaucrat << std::endl;
    try
    {
      bureaucrat.decrementGrade();
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }
    std::cout << bureaucrat << std::endl;
    try
    {
      bureaucrat.incrementGrade();
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }
    std::cout << bureaucrat << std::endl;
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
