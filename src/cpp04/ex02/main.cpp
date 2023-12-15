/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:47:15 by htsang            #+#    #+#             */
/*   Updated: 2023/09/21 11:15:41 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include <cstdlib>

#include <iostream>

namespace printer
{
  void  Animal(const Animal &animal)
  {
    std::cout << animal.getType() << " ";
    animal.makeSound();
  }

  void  Banner(const std::string &title)
  {
    std::cout << std::endl
              << "\e[90m===========================" << std::endl
              << title << std::endl
              << "===========================\e[0m" << std::endl << std::endl;
  }

  void  InteractivePrompt()
  {
    std::cout << "Enter a command (cat/dog/exit): ";
  }

  void  InteractivePromptRetry()
  {
    std::cerr << "Invalid command. Please try again: ";
  }
} // namespace printer

namespace noninteractive
{
  int Run()
  {
    int     amount = 10;
    Animal* animals[amount];

    printer::Banner("Animal constructors");
    for (int i = 0; i < amount; i++)
    {
      if (i % 2 == 0)
        animals[i] = new Dog();
      else
        animals[i] = new Cat();
    }
    printer::Banner("Animal destructors");
    for (int i = 0; i < amount; i++)
    {
      delete animals[i];
    }
    return EXIT_SUCCESS;
  }
} // namespace noninteractive

namespace interactive
{
  int RunCat()
  {
    printer::Banner("Cat constructor");
    Cat cat;
    {
      printer::Banner("Cat2 copy constructor");
      Cat cat2 = cat;
    }
    printer::Banner("Cat make sound");
    cat.makeSound();
    return EXIT_SUCCESS;
  }

  int RunDog()
  {
    printer::Banner("Dog constructor");
    Dog dog;
    {
      printer::Banner("Dog2 constructor");
      Dog dog2 = dog;
    }
    printer::Banner("Dog make sound");
    dog.makeSound();
    return EXIT_SUCCESS;
  }

  int Run()
  {
    std::string command;

    printer::InteractivePrompt();
    std::getline(std::cin, command);
    while (std::cin.good())
    {
      if (command == "cat")
        RunCat();
      else if (command == "dog")
        RunDog();
      else if (command == "exit")
        return EXIT_SUCCESS;
      else
      {
        printer::InteractivePromptRetry();
        std::getline(std::cin, command);
        continue ;
      }
      printer::InteractivePrompt();
      std::getline(std::cin, command);
    }
    return EXIT_SUCCESS;
  }
} // namespace interactive

int main(int argc, const char **argv)
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
