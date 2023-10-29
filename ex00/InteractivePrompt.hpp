/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InteractivePrompt.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:00:24 by htsang            #+#    #+#             */
/*   Updated: 2023/10/29 22:50:22 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

template <typename States>
class InteractivePrompt
{
  public:
    static const int  kActionLimit = 8;
    typedef int (*Action)(std::string input, States&);
    InteractivePrompt();
    InteractivePrompt(const InteractivePrompt& interactiveprompt);
    virtual ~InteractivePrompt();
    const InteractivePrompt& operator=(const InteractivePrompt& interactiveprompt);

    void  registerAction(std::string match, Action action);
    int   run(States& states);
    int   shell(States& states);

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
    std::string             prompt_;
    std::string             reprompt_;
    std::string             input_;
};

/////////////////////////////////////////////////////
////////////   template implementation   ////////////
/////////////////////////////////////////////////////

template <typename States>
InteractivePrompt<States>::InteractivePrompt()
  : prompt_(""),
    reprompt_("") {}

template <typename States>
InteractivePrompt<States>::InteractivePrompt(const InteractivePrompt& interactiveprompt)
  : prompt_(interactiveprompt.prompt_),
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
