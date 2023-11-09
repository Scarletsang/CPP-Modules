/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/11/09 20:57:37 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>

#include "InteractivePrompt.hpp"
#include "easyfind.hpp"

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
    std::cout << "Find result: " << easyfind(container, find) << std::endl;
    printContainer<T>(container);
  }
} // namespace test

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
} // namespace battle

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
