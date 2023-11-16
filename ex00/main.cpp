/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/11/16 18:14:57 by htsang           ###   ########.fr       */
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

  int Exit(std::string input, struct States& states)
  {
    (void)input;
    (void)states;
    return EXIT_FAILURE;
  }

  int Run()
  {
    struct States                     states;
    InteractivePrompt<struct States>  prompt;

    prompt.set_prompt("Enter a number");
    prompt.set_reprompt("Invalid input. Try again: ");
    prompt.register_action("exit", Exit);
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
    return noninteractive::Run(argv[1]);
  else if (argc == 3 && std::string(argv[1]) == "-i")
    return interactive::Run();
  else
  {
    std::cerr << "Usage: " << argv[0] << "filename [-i]" << std::endl;
    return EXIT_FAILURE;
  }
}
