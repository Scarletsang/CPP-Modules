/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/12/04 23:51:06 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include <iostream>
#include <string>
#include <list>
#include <stack>

#include "interactive/Prompt.hpp"
#include "InteractiveMutantStack.hpp"
#include "MutantStack.hpp"

namespace interactive
{
  int Exit(const std::string&, InteractiveMutantStack&)
  {
    return EXIT_FAILURE;
  }

  int Run()
  {
    InteractiveMutantStack  data;
    Prompt                  prompt;

    prompt.setPrompt("Enter a number");
    prompt.setReprompt("Invalid input. Try again: ");
    prompt.registerAction("exit", Action<InteractiveMutantStack, Exit>);
    prompt.shell(data);
    return EXIT_SUCCESS;
  }
} // namespace interactive

namespace test
{
  template <typename Container>
  int Test()
  {
    Container    container;
    container.push_back(5);
    container.push_back(17);
    std::cout << container.back() << std::endl;
    container.pop_back();
    std::cout << container.size() << std::endl;
    container.push_back(3);
    container.push_back(5);
    container.push_back(737);
    //[...]
    container.push_back(0);
    typename Container::iterator it = container.begin();
    typename Container::iterator ite = container.end();
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
    test::Test<MutantStack<int> >();
    std::cout << std::endl;
    test::Test<std::list<int> >();
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
