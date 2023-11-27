/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InteractivePrompt.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:12:55 by htsang            #+#    #+#             */
/*   Updated: 2023/11/27 23:29:56 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InteractivePrompt.hpp"

#include <string>
#include <iostream>

/////////////////////////////////////////
////////////   Prompt data   ////////////
/////////////////////////////////////////

InteractivePrompt::Data::Data() {}

InteractivePrompt::Data::Data(const InteractivePrompt::Data& promptdata) {}

InteractivePrompt::Data::~Data() {}

const InteractivePrompt::Data& InteractivePrompt::Data::operator=(const InteractivePrompt::Data& promptdata)
{
  return *this;
}

////////////////////////////////////////////////
////////////   Interactive prompt   ////////////
////////////////////////////////////////////////

InteractivePrompt::InteractivePrompt()
  : mode_(kMultipleChoice),
    prompt_(""),
    reprompt_("") {}

InteractivePrompt::InteractivePrompt(enum Mode mode)
  : mode_(mode),
    prompt_(""),
    reprompt_("") {}

InteractivePrompt::InteractivePrompt(const InteractivePrompt& interactiveprompt)
  : mode_(interactiveprompt.mode_),
    prompt_(interactiveprompt.prompt_),
    reprompt_(interactiveprompt.reprompt_)
{
  for (int i = 0; i < kActionLimit; i++)
  {
    settings_[i] = interactiveprompt.settings_[i];
  }
}

InteractivePrompt::~InteractivePrompt() {}

const InteractivePrompt& InteractivePrompt::operator=(const InteractivePrompt& interactiveprompt)
{
  if (this != &interactiveprompt)
  {
    mode_ = interactiveprompt.mode_;
    prompt_ = interactiveprompt.prompt_;
    reprompt_ = interactiveprompt.reprompt_;
    for (int i = 0; i < kActionLimit; i++)
    {
      settings_[i] = interactiveprompt.settings_[i];
    }
  }
  return *this;
}

void  InteractivePrompt::registerAction(std::string match, ActionFunc action)
{
  for (size_t i = 0; i < kActionLimit; i++)
  {
    if (settings_[i].match == "")
    {
      settings_[i].match = match;
      settings_[i].action = action;
      return ;
    }
  }
  throw std::runtime_error("InteractivePrompt::registerAction: maxiumum number of actions reached");
}

void  InteractivePrompt::setReprompt(std::string string)
{
  reprompt_ = string;
}

void  InteractivePrompt::setPrompt(std::string string)
{
  prompt_ = string;
}

int   InteractivePrompt::run(Data& states)
{
  if (!std::cout.good())
    return EXIT_FAILURE;

  switch (mode_)
  {
    case kMultipleChoice:
      return runMultipleChoice(states);
    case kForm:
      return runForm(states);
    default:
      break;
  }
  return EXIT_FAILURE;
}

int   InteractivePrompt::shell(Data& states)
{
  int exit_code;

  while (!(exit_code = run(states))) ;
  return exit_code;
}

void  InteractivePrompt::printPrompt() const
{
  std::cout << prompt_ << "(";
  for (size_t i = 0; i < kActionLimit; i++)
  {
    if (settings_[i].match != "")
      std::cout << settings_[i].match;
    if (i + 1 < kActionLimit && settings_[i + 1].match != "")
      std::cout << "/";
    else
      break ;
  }
  std::cout << "): ";
}

/////////////////////////////////////////////
////////////   private methods   ////////////
/////////////////////////////////////////////

int InteractivePrompt::runMultipleChoice(Data& states)
{
  printPrompt();
  std::getline(std::cin, input_);
  if (!input_.empty())
  {
    for (size_t i = 0; i < kActionLimit; i++)
    {
      if (input_ == settings_[i].match)
        return settings_[i].action(input_, states);
    }
  }
  while (std::cin.good() && !reprompt_.empty())
  {
    std::cout << reprompt_;
    std::getline(std::cin, input_);
    if (input_.empty())
      continue;
    for (size_t i = 0; i < kActionLimit; i++)
    {
      if (input_ == settings_[i].match)
        return settings_[i].action(input_, states);
    }
  }
  return EXIT_FAILURE;
}

int InteractivePrompt::runForm(Data& states)
{
  int exit_code = EXIT_SUCCESS;

  if (!prompt_.empty())
    std::cout << prompt_ << std::endl;
  for (int i = 0; (i < kActionLimit); i++)
  {
    if (!std::cin.good())
      return EXIT_FAILURE;
    else if (settings_[i].match == "")
      break ;
    std::cout << settings_[i].match << ": ";
    std::getline(std::cin, input_);
    exit_code = settings_[i].action(input_, states);
    if ((exit_code == EXIT_FAILURE) && !reprompt_.empty())
    {
      while (std::cin.good() && (exit_code == EXIT_FAILURE))
      {
        std::cout << reprompt_;
        std::getline(std::cin, input_);
        exit_code = settings_[i].action(input_, states);
      }
    }
  }
  return EXIT_SUCCESS;
}
