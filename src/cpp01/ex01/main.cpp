/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:27:44 by htsang            #+#    #+#             */
/*   Updated: 2023/07/19 02:28:30 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <cstdlib>

#include <limits>
#include <iostream>
#include <iomanip>
#include <string>

namespace test
{
  static const std::ios_base::iostate FailMask = std::ios_base::eofbit | std::ios_base::badbit;

  void  ClearLine(std::istream &input_stream)
  {
    input_stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  std::ios_base::iostate  HandleBadStream(std::istream &input_stream)
  {
    std::ios_base::iostate state = input_stream.rdstate();

    if (input_stream.eof())
    {
      return state;
    }
    else if (input_stream.fail())
    {
      std::cerr << "Invalid input. Please try again: ";
      input_stream.clear();
      ClearLine(input_stream);
    }
    else if (input_stream.bad())
    {
      std::cout << "Fatal error" << std::endl;
    }
    return state;
  }

  int  GetInt(int &n)
  {
    while (true)
    {
      std::cin >> std::setiosflags(std::ios_base::dec) >> n;
      if (std::cin.good())
        break;
      else if ((HandleBadStream(std::cin) & FailMask) > 0)
        return EXIT_FAILURE;
    }
    ClearLine(std::cin);
    return EXIT_SUCCESS;
  }

} // namespace test

namespace my
{
  void  PTestZombieHorde(int n, std::string name)
  {
    Zombie *zombie_horde = zombieHorde(n, name);
    for (int i = 0; i < n; i++)
    {
      zombie_horde[i].announce();
    }
    delete[] zombie_horde;
  }

  void  PTestZombieHordeRange(int from, int to, std::string name)
  {
    if (from > to)
    {
      for (int i = from; i >= to; i--)
      {
        PTestZombieHorde(i, name);
        std::cout << std::endl;
      }
    }
    else
    {
      for (int i = from; i <= to; i++)
      {
        PTestZombieHorde(i, name);
        std::cout << std::endl;
      }
    }
  }

  int  PromptZombieHorde(void)
  {
    std::string name;
    int         n;

    std::cout << "Enter the number of zombies: ";
    if (test::GetInt(n))
      return EXIT_FAILURE;
    std::cout << "Enter the name of the zombies: ";
    std::getline(std::cin, name);
    std::cout << std::endl;
    PTestZombieHorde(n, name);
    return EXIT_SUCCESS;
  }

  int  PromptZombieHordeRange(void)
  {
    std::string name;
    int         from;
    int         to;

    std::cout << "Enter the starting size of a zombie horde: ";
    if (test::GetInt(from))
      return EXIT_FAILURE;
    std::cout << "Enter the ending size of a zombie horde: ";
    if (test::GetInt(to))
      return EXIT_FAILURE;
    std::cout << "Enter the name of the zombies: ";
    std::getline(std::cin, name);
    std::cout << std::endl;
    PTestZombieHordeRange(from, to, name);
    return EXIT_SUCCESS;
  }

  void  Menu(void)
  {
    std::cout << "1. PTestZombieHorde" << std::endl;
    std::cout << "2. PTestZombieHordeRange" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "Enter your choice(1/2/3): ";
  }
} // namespace my

int main(void)
{
  std::string choice;

  my::Menu();
  std::getline(std::cin, choice);
  while (std::cin.good())
  {
    if (choice == "1")
    {
      if (my::PromptZombieHorde())
        break ;
      std::cout << std::endl;
    }
    else if (choice == "2")
    {
      if (my::PromptZombieHordeRange())
        break ;
    }
    else if (choice == "3")
      return EXIT_SUCCESS;
    else
      std::cout << "Invalid choice: '" << choice << "'" << std::endl;
    my::Menu();
    std::getline(std::cin, choice);
  }
  return EXIT_FAILURE;
}
