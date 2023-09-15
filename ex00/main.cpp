/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:47:15 by htsang            #+#    #+#             */
/*   Updated: 2023/09/15 19:47:50 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main()
{
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();

  std::cout << std::endl;

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;

  std::cout << std::endl;

  i->makeSound(); //will output the cat sound!
  j->makeSound();

  std::cout << std::endl;

  meta->makeSound();
  delete meta;
  delete j;
  delete i;

  std::cout << std::endl;

  const WrongAnimal *meta2 = new WrongAnimal();
  const WrongAnimal *j2 = new WrongCat();

  std::cout << std::endl;

  std::cout << j2->getType() << " " << std::endl;

  std::cout << std::endl;

  j2->makeSound();

  std::cout << std::endl;

  meta2->makeSound();
  delete meta2;
  delete j2;

  std::cout << std::endl;

  return (0);
}