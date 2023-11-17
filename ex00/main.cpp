/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/11/17 16:12:49 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include <iostream>
#include <string>

#include "InteractivePrompt.hpp"
#include "BitcoinExchange.hpp"

namespace interactive
{
  struct States
  {};

  int AddEntry(std::string& input, struct States& states)
  {
    (void)input;
    (void)states;
    return EXIT_FAILURE;
  }

  int Compare(std::string& input, struct States& states)
  {
    (void)input;
    (void)states;
    return EXIT_FAILURE;
  }

  int Query(std::string& input, struct States& states)
  {
    (void)input;
    (void)states;
    return EXIT_FAILURE;
  }

  int Print(std::string& input, struct States& states)
  {
    (void)input;
    (void)states;
    return EXIT_FAILURE;
  }

  int Exit(std::string& input, struct States& states)
  {
    (void)input;
    (void)states;
    return EXIT_FAILURE;
  }

  int Run()
  {
    struct States                     states;
    InteractivePrompt<struct States>  prompt;

    prompt.set_prompt("What do you want to do?");
    prompt.set_reprompt("Invalid input. Try again: ");
    prompt.register_action("exit", Exit);
    prompt.register_action("Add", AddEntry);
    prompt.register_action("compare", Compare);
    prompt.register_action("query", Query);
    prompt.register_action("print", Print);
    prompt.shell(states);
    return EXIT_SUCCESS;
  }
} // namespace interactive

namespace noninteractive
{
  int Run(const char *filename)
  {
    BitcoinExchange bitcoin_exchange;

    bitcoin_exchange.entries_from_file("./data.csv", ",", false);
    return bitcoin_exchange.compare_entries_from_file(filename, "|");
  }
} // namespace noninteractive

int main(int argc, const char** argv)
{
  if (argc == 2)
  {
    if (std::string(argv[1]) == "-i")
      return interactive::Run();
    else
      return noninteractive::Run(argv[1]);
  }
  else
  {
    std::cerr << "Usage: " << argv[0] << "filename [-i]" << std::endl;
    return EXIT_FAILURE;
  }
}
