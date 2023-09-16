/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 22:34:03 by htsang            #+#    #+#             */
/*   Updated: 2023/09/16 22:51:55 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "materias/AMateria.hpp"
#include "materias/Ice.hpp"
#include "materias/Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

#include <cstdlib>

int main()
{
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  ICharacter* me = new Character("me");
  AMateria* tmp;

  tmp = src->createMateria("ice"); me->equip(tmp);
  tmp = src->createMateria("cure"); me->equip(tmp);

  ICharacter* bob = new Character("bob"); me->use(0, *bob);
  me->use(1, *bob);

  delete bob;
  delete me;
  delete src;

  return EXIT_SUCCESS;
}
