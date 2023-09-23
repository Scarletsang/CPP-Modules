/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/09/24 01:24:44 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "interactive.hpp"
#include "Vector.hpp"

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
      std::cerr << e.what() << std::endl;
    }
    std::cout << *bureaucrat << std::endl;
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
      std::cerr << e.what() << std::endl;
    }
    std::cout << *bureaucrat << std::endl;
    return EXIT_SUCCESS;
  }

  int RunForm(std::string& input, Vector<AForm*>& forms)
  {
    AForm  *form;

    printer::ShowForms(forms);
    if (parser::ParseUntilCorrect(input, form))
      return EXIT_FAILURE;
    forms.push_back(form);
    return EXIT_SUCCESS;
  }

  int RunSign(std::string& input, Vector<AForm*>& forms, Bureaucrat* bureaucrat)
  {
    s_index     index;

    if (forms.size() == 0)
    {
      printer::NoFormError();
      return EXIT_SUCCESS;
    }
    printer::ShowForms(forms);
    index.upper_bound = forms.size();
    if (parser::ParseWithPrompt(input, index, printer::ChooseFormPrompt))
      return EXIT_FAILURE;
    bureaucrat->signForm(*forms[index.number]);
    return EXIT_SUCCESS;
  }

  void  Cleanup(Vector<AForm*>& forms, Bureaucrat* bureaucrat)
  {
    for (size_t i = 0; i < forms.size(); i++)
    {
      delete forms[i];
      forms[i] = NULL;
    }
    delete bureaucrat;
  }

  int Run()
  {
    std::string   input;
    Bureaucrat*   bureaucrat;
    Vector<AForm*> forms;
    int           exit_code;

    if (parser::ParseUntilCorrect(input, bureaucrat))
      return EXIT_FAILURE;
    printer::InteractivePrompt();
    std::getline(std::cin, input);
    while (std::cin.good())
    {
      exit_code = EXIT_SUCCESS;
      if (input == "+")
        exit_code = RunIncrement(bureaucrat);
      else if (input == "-")
        exit_code = RunDecrement(bureaucrat);
      else if (input == "form")
        exit_code = RunForm(input, forms);
      else if (input == "sign")
        exit_code = RunSign(input, forms, bureaucrat);
      else if (input == "print")
      {
        std::cout << *bureaucrat << std::endl;
        printer::ShowForms(forms);
      }
      else if (input == "exit")
      {
        Cleanup(forms, bureaucrat);
        return EXIT_SUCCESS;
      }
      else
      {
        printer::InteractiveInvalidPrompt();
        std::getline(std::cin, input);
        continue ;
      }
      if (exit_code)
        break ;
      printer::InteractivePrompt();
      std::getline(std::cin, input);
    }
    Cleanup(forms, bureaucrat);
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
    AForm  form("missile launching agreement", 1, 1);
    AForm  form2("car crash report", 150, 150);
    bureaucrat.signForm(form);
    bureaucrat.signForm(form2);
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
