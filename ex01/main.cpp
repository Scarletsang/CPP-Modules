/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:47:15 by htsang            #+#    #+#             */
/*   Updated: 2023/09/20 17:30:25 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include <cstdlib>

#include <iostream>

int main(int argc, char **argv)
{
  int amount;

  if (argc == 1)
    amount = 1;
  else if (argc == 2)
    amount = atoi(argv[1]);
  else
  {
    std::cout << "Too many arguments" << std::endl;
    return EXIT_FAILURE;
  }
  if (amount == 0)
  {
    std::cout << "Amount of animals cannot be 0" << std::endl;
    return EXIT_FAILURE;
  }
  Animal *animals[amount];

  for (int i = 0; i < amount; i++)
  {
    if (i % 2 == 0)
      animals[i] = new Dog();
    else
      animals[i] = new Cat();
  }
  for (int i = 0; i < amount; i++)
  {
    delete animals[i];
  }
  return EXIT_SUCCESS;
}
