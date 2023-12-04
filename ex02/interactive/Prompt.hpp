/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Prompt.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:00:24 by htsang            #+#    #+#             */
/*   Updated: 2023/12/04 21:40:48 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <cstdlib>

#include "Data.hpp"

namespace interactive
{
  typedef int (*ActionFunc)(const std::string& input, Data&);

  /**
   * @brief A class that create an interactive prompt
  */
  class Prompt
  {
    public:

      ///////////////////////////////////
      ////////////   types   ////////////
      ///////////////////////////////////

      enum  Mode
      {
        kMultipleChoice,
        kForm
      };

      static const int  kActionLimit = 8;

      //////////////////////////////////////////
      ////////////   constructors   ////////////
      //////////////////////////////////////////

      Prompt();
      /**
       * @brief The interactive prompt provides two modes:
       * 1. kMultipleChoice: the user is prompted for a choice among a list of options
       * 2. kForm: the user is prompted for a list of values
      */
      Prompt(enum Mode mode);
      Prompt(const Prompt& Prompt);
      virtual ~Prompt();
      const Prompt& operator=(const Prompt& Prompt);

      /**
       * @brief Register an action to be executed when the user enters a specific input
       * @param match The input that triggers the action. In kForm mode, this is acting as
       * a prompt for the user to enter a value
       * @param action The action to be executed. In kForm mode, this is acting as a parser
      */
      void  registerAction(std::string match, ActionFunc action);
      int   run(Data& states);
      int   shell(Data& states);

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
        std::string         match;
        ActionFunc          action;
      };
      struct Configuration    settings_[kActionLimit];
      enum Mode               mode_;
      std::string             prompt_;
      std::string             reprompt_;
      std::string             input_;

      int runMultipleChoice(Data& states);
      int runForm(Data& states);
  };

  /////////////////////////////////////////////////////
  ////////////   template implementation   ////////////
  /////////////////////////////////////////////////////

  template <typename Data>
  int   Run(int (*f)(const std::string& input, Data&),
            Data& data,
            const std::string& prompt = "",
            const std::string& reprompt = "")
  {
    std::string input;

    if (!std::cin.good())
      return EXIT_FAILURE;
    else if (!prompt.empty())
      std::cout << prompt << ": " << std::endl;
    std::getline(std::cin, input);
    while (std::cin.good())
    {
      if (f(input, data) == EXIT_SUCCESS)
        return EXIT_SUCCESS;
      else if (!reprompt.empty())
        std::cout << reprompt << ": " << std::endl;
      std::getline(std::cin, input);
    }
    return EXIT_FAILURE;
  }

  template <typename Data, int (*ActionFunction)(const std::string& input, Data&)>
  int   Action(const std::string& input, interactive::Data& data)
  {
    return ActionFunction(input, static_cast<Data&>(data));
  }

} // namespace interactive
