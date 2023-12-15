/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/12/05 14:45:01 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include <iostream>
#include <string>
#include <vector>
#include <utility>

#include "interactive/Prompt.hpp"
#include "InteractiveSpan.hpp"
#include "Span.hpp"

namespace interactive
{
  int AddNumberAction(const std::string&, InteractiveSpan& data)
  {
    int exit_code = data.addNumber();

    if (exit_code == EXIT_SUCCESS)
      data.print();
    return exit_code;
  }

  int StatusAction(const std::string&, InteractiveSpan& data)
  {
    try
    {
      data.status();
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
      return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
  }

  int PrintAction(const std::string&, InteractiveSpan& data)
  {
    data.print();
    return EXIT_SUCCESS;
  }

  int Exit(const std::string&, InteractiveSpan&)
  {
    return EXIT_FAILURE;
  }

  int Run()
  {
    InteractiveSpan     data;
    Prompt              prompt;

    prompt.setPrompt("Choose an action");
    prompt.setReprompt("Invalid input. Try again: ");
    prompt.registerAction("add", Action<InteractiveSpan, AddNumberAction>);
    prompt.registerAction("status", Action<InteractiveSpan, StatusAction>);
    prompt.registerAction("print", Action<InteractiveSpan, PrintAction>);
    prompt.registerAction("exit", Action<InteractiveSpan, Exit>);
    prompt.shell(data);
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
