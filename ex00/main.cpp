/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:47:15 by htsang            #+#    #+#             */
/*   Updated: 2023/09/21 10:30:29 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <cstdlib>

#include <iostream>
#include <string>

namespace printer
{
  void  Animal(const Animal &animal)
  {
    std::cout << animal.getType() << " ";
    animal.makeSound();
  }

  void  WrongAnimal(const WrongAnimal &animal)
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
    std::cout << "Enter a command (animal/cat/dog/wronganimal/wrongcat/exit): ";
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
    printer::Banner("Animals constructors");
    const Animal *animal = new Animal();
    const Animal *dog = new Dog();
    const Animal *cat = new Cat();

    printer::Banner("Animals make sound");
    printer::Animal(*animal);
    printer::Animal(*dog);
    printer::Animal(*cat);

    printer::Banner("Animals destructors");
    delete animal;
    delete dog;
    delete cat;

    printer::Banner("Wrong animals constructors");
    const WrongAnimal *wrong_animal = new WrongAnimal();
    const WrongAnimal *wrong_cat = new WrongCat();

    printer::Banner("Wrong animals make sound");
    printer::WrongAnimal(*wrong_animal);
    printer::WrongAnimal(*wrong_cat);

    printer::Banner("Wrong animals destructors");
    delete wrong_animal;
    delete wrong_cat;

    return EXIT_SUCCESS;
  }
} // namespace noninteractive

namespace interactive
{
  void  RunAnimal()
  {
    printer::Banner("Animal constructor");
    const Animal *animal = new Animal();

    printer::Banner("Animal make sound");
    printer::Animal(*animal);

    printer::Banner("Animal destructor");
    delete animal;
  }

  void  RunCat()
  {
    printer::Banner("Cat constructor");
    const Animal *cat = new Cat();

    printer::Banner("Cat make sound");
    printer::Animal(*cat);

    printer::Banner("Cat destructor");
    delete cat;
  }

  void  RunDog()
  {
    printer::Banner("Dog constructor");
    const Animal *dog = new Dog();

    printer::Banner("Dog make sound");
    printer::Animal(*dog);

    printer::Banner("Dog destructor");
    delete dog;
  }

  void  RunWrongAnimal()
  {
    printer::Banner("Wrong animal constructor");
    const WrongAnimal *wrong_animal = new WrongAnimal();

    printer::Banner("Wrong animal make sound");
    printer::WrongAnimal(*wrong_animal);

    printer::Banner("Wrong animal destructor");
    delete wrong_animal;
  }

  void  RunWrongCat()
  {
    printer::Banner("Wrong cat constructor");
    const WrongAnimal *wrong_cat = new WrongCat();

    printer::Banner("Wrong cat make sound");
    printer::WrongAnimal(*wrong_cat);

    printer::Banner("Wrong cat destructor");
    delete wrong_cat;
  }

  int Run()
  {
    std::string input;

    printer::InteractivePrompt();
    std::getline(std::cin, input);
    while (std::cin.good())
    {
      if (input == "animal")
        RunAnimal();
      else if (input == "cat")
        RunCat();
      else if (input == "dog")
        RunDog();
      else if (input == "wronganimal")
        RunWrongAnimal();
      else if (input == "wrongcat")
        RunWrongCat();
      else if (input == "exit")
        return EXIT_SUCCESS;
      else
      {
        printer::InteractivePromptRetry();
        std::getline(std::cin, input);
        continue ;
      }
      printer::InteractivePrompt();
      std::getline(std::cin, input);
    }
    return EXIT_FAILURE;
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
