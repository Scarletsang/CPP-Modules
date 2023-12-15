/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/11/28 15:54:55 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <utility>
#include <iterator>

#include "InteractivePrompt.hpp"
#include "InteractiveData.hpp"
#include "easyfind.hpp"

namespace interactive
{
  typedef std::pair<bool, int> ParserResult;

  ParserResult  ParseInt(const std::string& input)
  {
    int i = std::atoi(input.c_str());
    if (i == 0 && input != "0")
      return std::make_pair(false, 0);
    return std::make_pair(true, i);
  }

  int SetSizeAction(const std::string& input, InteractiveData& data)
  {
    ParserResult result = ParseInt(input);
    
    if (result.first)
    {
      data.generate(result.second);
      data.print();
      return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
  }

  int FindAction(const std::string& input, InteractiveData& data)
  {
    ParserResult result = ParseInt(input);
    
    if (result.first)
    {
      data.print_element(result.second);
      return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
  }

  int Run()
  {
    InteractiveData   data;
    InteractivePrompt prompt(InteractivePrompt::kForm);

    prompt.setReprompt("Invalid input. Try again: ");
    prompt.registerAction("Please enter the amount of numbers to randomize", 
      InteractivePrompt::Action<InteractiveData, SetSizeAction>);
    prompt.registerAction("Please enter the number you want to find", 
      InteractivePrompt::Action<InteractiveData, FindAction>);
    return prompt.run(data);
  }
} // namespace interactive

namespace noninteractive
{
  int Run()
  {
    InteractiveData   data;

    data.generate(10);
    data.print();
    data.print_element(5);
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
