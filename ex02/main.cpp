/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/12/05 15:58:45 by htsang           ###   ########.fr       */
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
  int GetIntAction(const std::string&input, PrimitiveData<int>& int_data)
  {
    int i = std::atoi(input.c_str());
    if (i == 0 && input != "0")
      return EXIT_FAILURE;
    else
      int_data.data() = i;
    return EXIT_SUCCESS;
  }

  int PushAction(const std::string&, InteractiveMutantStack& mutant_stacks)
  {
    PrimitiveData<int>  int_data;
    if (RunActionFunc(GetIntAction, int_data, "Enter a value to push", "Invalid input. Try again"))
      return EXIT_FAILURE;
    mutant_stacks.push(int_data.data());
    mutant_stacks.print();
    return EXIT_SUCCESS;
  }

  int PopAction(const std::string&, InteractiveMutantStack& mutant_stacks)
  {
    if (mutant_stacks.empty())
    {
      std::cout << "Pop from empty stacks are forbidden." << std::endl;
      return EXIT_SUCCESS;
    }
    mutant_stacks.pop();
    mutant_stacks.print();
    return EXIT_SUCCESS;
  }

  int PrintAction(const std::string&, InteractiveMutantStack& mutant_stacks)
  {
    mutant_stacks.print();
    return EXIT_SUCCESS;
  }

  int Exit(const std::string&, InteractiveMutantStack&)
  {
    return EXIT_FAILURE;
  }

  int Run()
  {
    InteractiveMutantStack  data;
    Prompt                  prompt;

    prompt.setPrompt("Choose an action");
    prompt.setReprompt("Invalid input. Try again: ");
    prompt.registerAction("push", Action<InteractiveMutantStack, PushAction>);
    prompt.registerAction("pop", Action<InteractiveMutantStack, PopAction>);
    prompt.registerAction("print", Action<InteractiveMutantStack, PrintAction>);
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
