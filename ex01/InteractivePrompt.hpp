/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InteractivePrompt.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:00:24 by htsang            #+#    #+#             */
/*   Updated: 2023/11/24 20:28:18 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

/**
 * @brief A class that create an interactive prompt
*/
template <typename States>
class InteractivePrompt
{
  public:
    static const int  kActionLimit = 8;
    typedef int (*Action)(std::string input, States&);
    enum  Mode
    {
      kMultipleChoice,
      kForm
    };

    InteractivePrompt();
    /**
     * @brief The interactive prompt provides two modes:
     * 1. kMultipleChoice: the user is prompted for a choice among a list of options
     * 2. kForm: the user is prompted for a list of values
    */
    InteractivePrompt(enum Mode mode);
    InteractivePrompt(const InteractivePrompt& interactiveprompt);
    virtual ~InteractivePrompt();
    const InteractivePrompt& operator=(const InteractivePrompt& interactiveprompt);

    /**
     * @brief Register an action to be executed when the user enters a specific input
     * @param match The input that triggers the action. In kForm mode, this is acting as
     * a prompt for the user to enter a value
     * @param action The action to be executed. In kForm mode, this is acting as a parser
    */
    void  registerAction(std::string match, Action action);
    int   run(States& states);
    int   shell(States& states);

    /**
     * @brief Set the reprompt message. It is printed when the user enters an invalid input.
     * When it is not set, user will not be prompted again for an invalid input.
     * @param string The reprompt message
    */
    void  setReprompt(std::string string);
    void  setPrompt(std::string string);

    void  printPrompt() const;

  private:
    struct  Configuration
    {
      std::string match;
      Action      action;
    };
    struct Configuration    settings_[kActionLimit];
    enum Mode               mode_;
    std::string             prompt_;
    std::string             reprompt_;
    std::string             input_;

    int runMultipleChoice(States& states);
    int runForm(States& states);
};

/////////////////////////////////////////////////////
////////////   template implementation   ////////////
/////////////////////////////////////////////////////

template <typename States>
InteractivePrompt<States>::InteractivePrompt()
  : mode_(kMultipleChoice),
    prompt_(""),
    reprompt_("") {}

template <typename States>
InteractivePrompt<States>::InteractivePrompt(enum Mode mode)
  : mode_(mode),
    prompt_(""),
    reprompt_("") {}

template <typename States>
InteractivePrompt<States>::InteractivePrompt(const InteractivePrompt& interactiveprompt)
  : mode_(interactiveprompt.mode_),
    prompt_(interactiveprompt.prompt_),
    reprompt_(interactiveprompt.reprompt_)
{
  for (int i = 0; i < kActionLimit; i++)
  {
    settings_[i] = interactiveprompt.settings_[i];
  }
}

template <typename States>
InteractivePrompt<States>::~InteractivePrompt() {}

template <typename States>
const InteractivePrompt<States>& InteractivePrompt<States>::operator=(const InteractivePrompt& interactiveprompt)
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

template <typename States>
void  InteractivePrompt<States>::registerAction(std::string match, Action action)
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

template <typename States>
void  InteractivePrompt<States>::setReprompt(std::string string)
{
  reprompt_ = string;
}

template <typename States>
void  InteractivePrompt<States>::setPrompt(std::string string)
{
  prompt_ = string;
}

template <typename States>
int   InteractivePrompt<States>::run(States& states)
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

template <typename States>
int   InteractivePrompt<States>::shell(States& states)
{
  int exit_code;

  while (!(exit_code = run(states))) ;
  return exit_code;
}

template <typename States>
void  InteractivePrompt<States>::printPrompt() const
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

template <typename States>
int InteractivePrompt<States>::runMultipleChoice(States& states)
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

template <typename States>
int InteractivePrompt<States>::runForm(States& states)
{
  int exit_code = EXIT_SUCCESS;

  if (!prompt_.empty())
    std::cout << prompt_ << std::endl;
  for (int i = 0; (i < kActionLimit) && std::cin.good(); i++)
  {
    if (settings_[i].match.empty())
      break;
    else
      std::cout << settings_[i].match << ": ";
    std::getline(std::cin, input_);
    exit_code = settings_[i].action(input_, states);
    if (!reprompt_.empty())
    {
      while (std::cin.good() && (exit_code == EXIT_FAILURE))
      {
        std::cout << reprompt_;
        std::getline(std::cin, input_);
        exit_code = settings_[i].action(input_, states);
      }
    }
  }
  return std::cin.good() ? exit_code : EXIT_FAILURE;
}
