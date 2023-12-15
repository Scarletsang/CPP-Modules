/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 22:39:24 by htsang            #+#    #+#             */
/*   Updated: 2023/09/23 23:13:40 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

namespace interactive
{

  namespace printer
  {
    typedef void (&Printer)();

    void  InteractivePrompt();

    void  CharacterNamePrompt();

    void  CharacterGradePrompt();

    void  InteractiveInvalidPrompt();
  } // namespace printer

  namespace parser
  {
    int Parse(std::string& input, int& number);

    int Parse(std::string& input, std::string& string);
    
    int Parse(std::string& input, Bureaucrat*& bureaucrat);

    template <typename T>
    int ParseWithPrompt(std::string& input, T& target, printer::Printer prompt)
    {
      prompt();
      std::getline(std::cin, input);
      while (std::cin.good())
      {
        if (!Parse(input, target))
          return EXIT_SUCCESS;
        else
        {
          printer::InteractiveInvalidPrompt();
          std::getline(std::cin, input);
        }
      }
      return EXIT_FAILURE;
    }

    template <typename T>
    int ParseUntilCorrect(std::string& input, T& target)
    {
      while (std::cin.good())
      {
        if (!Parse(input, target))
          return EXIT_SUCCESS;
      }
      return EXIT_FAILURE;
    }
  } // namespace parser

} // namespace interactive

