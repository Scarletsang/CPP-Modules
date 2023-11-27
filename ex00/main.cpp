/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/11/28 00:01:53 by htsang           ###   ########.fr       */
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

namespace test
{
  template <typename T>
  T  createContainer(int size)
  {
    T container;

    for (int i = 0; i < size; i++)
      container.push_back(i);
    return container;
  }

  template <typename T>
  void  printContainer(T& container)
  {
    for (typename T::iterator it = container.begin(); it != container.end(); it++)
    {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
  }

  template <typename T>
  void  Test(int size, int find)
  {
    T container = createContainer<T>(size);
    typename T::iterator it = easyfind(container, find);
    std::cout << "Find result " << *it << " at index " << (it - container.begin()) << std::endl;
    printContainer<T>(container);
  }
} // namespace test

namespace noninteractive
{
  int Run()
  {
    test::Test<std::vector<int> >(10, 5);
    test::Test<std::deque<int> >(10, 5);
    test::Test<std::list<int> >(10, 5);
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
