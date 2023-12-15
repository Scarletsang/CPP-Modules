/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:27:44 by htsang            #+#    #+#             */
/*   Updated: 2023/07/18 21:58:15 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>
#include <string>

namespace my
{
  void  TestZombieOnStack(void)
  {
    randomChump("firstZombie");
    randomChump("secondZombie");
    randomChump("thirdZombie");
  }

  void  TestZombieOnHeap(void)
  {
    Zombie *firstZombie = newZombie("firstZombie");
    Zombie *secondZombie = newZombie("secondZombie");
    Zombie *thirdZombie = newZombie("thirdZombie");

    firstZombie->announce();
    secondZombie->announce();
    thirdZombie->announce();

    delete firstZombie;
    delete secondZombie;
    delete thirdZombie;
  }

  void  TestZombieOneAfterAnotherOnHeap(void)
  {
    {
      Zombie *firstZombie = newZombie("firstZombie");
      firstZombie->announce();
      delete firstZombie;
    }
    {
      Zombie *secondZombie = newZombie("secondZombie");
      secondZombie->announce();
      delete secondZombie;
    }
    {
      Zombie *thirdZombie = newZombie("thirdZombie");
      thirdZombie->announce();
      delete thirdZombie;
    }
  }

  void  TestMenu(void)
  {
    std::cout << "1. TestZombieOnStack" << std::endl;
    std::cout << "2. TestZombieOnHeap" << std::endl;
    std::cout << "3. TestZombieOneAfterAnotherOnHeap" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Enter your choice(1/2/3/4): ";
  }
}

int main(void)
{
  std::string choice;

  my::TestMenu();
  while (!std::getline(std::cin, choice).eof())
  {
    std::cout << std::endl;
    if (choice == "1")
      my::TestZombieOnStack();
    else if (choice == "2")
      my::TestZombieOnHeap();
    else if (choice == "3")
      my::TestZombieOneAfterAnotherOnHeap();
    else if (choice == "4")
      break;
    else
      std::cout << "Invalid choice" << std::endl;
    std::cout << std::endl;
    my::TestMenu();
  }
}
