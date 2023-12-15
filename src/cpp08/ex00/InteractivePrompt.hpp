/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InteractivePrompt.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:00:24 by htsang            #+#    #+#             */
/*   Updated: 2023/11/27 23:29:37 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

/**
 * @brief A class that create an interactive prompt
*/
class InteractivePrompt
{
  public:
    static const int  kActionLimit = 8;

    class Data
    {
      public:
        Data();
        Data(const Data& promptdata);
        virtual ~Data();
        const Data& operator=(const Data& promptdata);
    };

    template <typename Data, int (*ActionFunction)(const std::string& input, Data&)>
    static int   Action(const std::string& input, InteractivePrompt::Data& states)
    {
      return ActionFunction(input, static_cast<Data&>(states));
    }

    typedef int (*ActionFunc)(const std::string& input, Data&);
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
      std::string match;
      ActionFunc      action;
    };
    struct Configuration    settings_[kActionLimit];
    enum Mode               mode_;
    std::string             prompt_;
    std::string             reprompt_;
    std::string             input_;

    int runMultipleChoice(Data& states);
    int runForm(Data& states);
};
