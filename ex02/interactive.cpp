/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 22:37:48 by htsang            #+#    #+#             */
/*   Updated: 2023/10/10 16:38:22 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interactive.hpp"

#include <cstdlib>

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Vector.hpp"

namespace interactive
{
  namespace printer
  {
    void  InteractivePrompt()
    {
      std::cout << "Please enter a command (+/-/form/sign/execute/print/exit): ";
    }

    void  CharacterNamePrompt()
    {
      std::cout << "Please enter a name for your character: ";
    }

    void  CharacterGradePrompt()
    {
      std::cout << "Please enter a grade for your character: ";
    }

    void  FormTargetPrompt()
    {
      std::cout << "Please enter a target for your form: ";
    }

    void  FormTypePrompt()
    {
      std::cout << "Please enter the kind of form you want to make (presidential/robotomy/shrubbery): ";
    }

    void  ChooseFormPrompt()
    {
      std::cout << "Please choose a form (index): ";
    }

    void  ShowForms(Vector<AForm*>& forms)
    {
      if (forms.size() <= 0)
        return ;
      std::cout << "Forms:" << std::endl;
      for (size_t i = 0; i < forms.size(); i++)
        std::cout << i << ": " << *forms[i] << std::endl;
    }

    void  NoFormError()
    {
      std::cerr << "No forms available." << std::endl;
    }

    void  InteractiveInvalidIndexPrompt()
    {
      std::cerr << "Invalid index. Please try again: ";
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
      return EXIT_SUCCESS;
    }

    int Parse(std::string& input, struct s_index& index)
    {
      index.number = std::atoi(input.c_str());
      return (index.number < 0 || index.number >= index.upper_bound);
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

