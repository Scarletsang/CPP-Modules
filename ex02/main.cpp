/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/11/09 23:46:11 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include <iostream>
#include <string>
#include <list>
#include <stack>

#include "InteractivePrompt.hpp"
#include "MutantStack.hpp"

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

namespace test
{
  int  TestWithMutantStack()
  {
    MutantStack<int>    mstack;
    mstack.push_back(5);
    mstack.push_back(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    //[...]
    mstack.push_back(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while(it != ite){
      std::cout << *it << std::endl;
      ++it;
    }
    return EXIT_SUCCESS;
  }

  int TestWithList()
  {
    std::list<int>    list;
    list.push_back(5);
    list.push_back(17);
    std::cout << list.back() << std::endl;
    list.pop_back();
    std::cout << list.size() << std::endl;
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    //[...]
    list.push_back(0);
    std::list<int>::iterator it = list.begin();
    std::list<int>::iterator ite = list.end();
    ++it;
    --it;
    while(it != ite){
      std::cout << *it << std::endl;
      ++it;
    }
    return EXIT_SUCCESS;
  }

  int CheckMutantStackInheritance()
  {
    MutantStack<int>    mstack;
    mstack.push(5);
    mstack.push(17);
    std::stack<int> s(mstack);
    return EXIT_SUCCESS;
  }
} // namespace test

namespace noninteractive
{
  int Run()
  {
    test::TestWithMutantStack();
    std::cout << std::endl;
    test::TestWithList();
    if (test::CheckMutantStackInheritance() == EXIT_FAILURE)
    {
      std::cerr << "MutantStack does not inherit from std::stack" << std::endl;
      return EXIT_FAILURE;
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
