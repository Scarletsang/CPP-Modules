/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 22:37:48 by htsang            #+#    #+#             */
/*   Updated: 2023/11/21 16:39:48 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interactive.hpp"

#include <cstdlib>

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

namespace interactive
{
  namespace printer
  {
    void  InteractivePrompt()
    {
      std::cout << "Please enter a command (+/-/exit): ";
    }

    void  CharacterNamePrompt()
    {
      std::cout << "Please enter a name for your character: ";
    }

    void  CharacterGradePrompt()
    {
      std::cout << "Please enter a grade for your character: ";
    }

    void  InteractiveInvalidPrompt()
    {
      std::cerr << "Invalid input. Please try again: ";
    }
  } // namespace printer

  namespace parser
  {
    int Parse(std::string& input, int& number)
    {
      number = std::atoi(input.c_str());
      if (number == 0 && input[0] != '0' && input.size() != 1)
        return EXIT_FAILURE;
      return EXIT_SUCCESS;
    }

    int Parse(std::string& input, std::string& string)
    {
      string = input;
      return EXIT_SUCCESS;
    }

    int Parse(std::string& input, Bureaucrat*& bureaucrat)
    {
      std::string name;
      int         grade;

      try
      {
        if (ParseWithPrompt(input, name, printer::CharacterNamePrompt) ||
            ParseWithPrompt(input, grade, printer::CharacterGradePrompt))
          return EXIT_FAILURE;
        bureaucrat = new Bureaucrat(name, grade);
        return EXIT_SUCCESS;
      }
      catch (std::exception& e)
      {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
      }
    }
  } // namespace parser

} // namespace interactive

