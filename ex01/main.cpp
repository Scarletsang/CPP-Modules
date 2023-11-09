/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/11/09 23:37:26 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include <iostream>
#include <string>
#include <vector>

#include "InteractivePrompt.hpp"
#include "Span.hpp"

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

    prompt.setPrompt("Enter a number");
    prompt.setReprompt("Invalid input. Try again: ");
    prompt.registerAction("exit", Exit);
    prompt.shell(states);
    return EXIT_SUCCESS;
  }
} // namespace interactive

namespace noninteractive
{
  int Run()
  {
    std::vector<int> v;
    v.push_back(5);
    v.push_back(3);
    v.push_back(17);
    v.push_back(9);
    v.push_back(11);
    {
      Span sp = Span(5);
      sp.addNumbers(v.begin(), v.end());
      std::cout << sp.shortestSpan() << std::endl;
      std::cout << sp.longestSpan() << std::endl;
    }
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
