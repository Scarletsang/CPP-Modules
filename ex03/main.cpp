/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 22:34:03 by htsang            #+#    #+#             */
/*   Updated: 2023/09/20 00:13:59 by htsang           ###   ########.fr       */
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

namespace interactive
{
  int PromptLearnMateria(MateriaSource* src)
  {
    std::string type;

    src->print();
    std::cout << "Enter materia type to learn (ice/cure) Type exit to enter the next session: ";
    std::getline(std::cin, type);
    while (std::cin.good())
    {
      if (type == "ice")
        src->learnMateria(new Ice());
      else if (type == "cure")
        src->learnMateria(new Cure());
      else if (type == "exit")
        return EXIT_SUCCESS;
      else
        std::cout << "Invalid materia type. Try again: ";
      src->print();
      std::cout << "Enter materia type to learn (ice/cure) Type exit to enter the next session: ";
      std::getline(std::cin, type);
    }
    return EXIT_FAILURE;
  }

  int PromptCharacter(Character** me)
  {
    std::string name;

    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    if (std::cin.good())
    {
      *me = new Character(name);
      return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
  }

  int PromptCharacterEquip(Character* me, IMateriaSource* src)
  {
    std::string type;

    std::cout << "Enter materia type to equip (ice/cure): ";
    std::getline(std::cin, type);
    while (std::cin.good())
    {
      if (type == "ice" || type == "cure")
      {
        me->equip(src->createMateria(type));
        return EXIT_SUCCESS;
      }
      else
        std::cout << "Invalid materia type. Try again: ";
      std::getline(std::cin, type);
    }
    return EXIT_SUCCESS;
  }

  int PromptCharacterUse(Character* me, Character* bob)
  {
    int         idx;
    std::string type;

    std::cout << "Enter materia index to use: ";
    std::getline(std::cin, type);
    while (std::cin.good())
    {
      idx = std::atoi(type.c_str());
      if (idx >= 0 || idx <= 3)
      {
        me->use(idx, *bob);
        return EXIT_SUCCESS;
      }
      else
        std::cout << "Invalid materia index. Try again: ";
      std::getline(std::cin, type);
    }
    return EXIT_SUCCESS;
  }

  int PromptCharacterUnequip(Character* me)
  {
    int         idx;
    std::string type;

    std::cout << "Enter materia index to unequip: ";
    std::getline(std::cin, type);
    while (std::cin.good())
    {
      idx = std::atoi(type.c_str());
      if (idx >= 0 || idx <= 3)
      {
        me->unequip(idx);
        return EXIT_SUCCESS;
      }
      else
        std::cout << "Invalid materia index. Try again: ";
      std::getline(std::cin, type);
    }
    return EXIT_SUCCESS;
  }

  int PromptCharacterActions(Character* me, Character* bob, IMateriaSource* src)
  {
    std::string action;
    std::string type;

    me->print();
    std::cout << "Enter your action (equip/use/unequip): ";
    std::getline(std::cin, action);
    while (std::cin.good())
    {
      if (action == "equip")
      {
        if (PromptCharacterEquip(me, src))
          return EXIT_FAILURE;
      }
      else if (action == "use")
      {
        if (PromptCharacterUse(me, bob))
          return EXIT_FAILURE;
      }
      else if (action == "unequip")
      {
        if (PromptCharacterUnequip(me))
          return EXIT_FAILURE;
      }
      else
      {
        std::cout << "Invalid action. Try again: ";
        std::getline(std::cin, action);
        continue;
      }
      me->print();
      std::cout << "Enter your action (equip/use/unequip): ";
      std::getline(std::cin, action);
    }
    return EXIT_SUCCESS;
  }

  void  cleanup(ICharacter* me, IMateriaSource* src)
  {
    if (me)
      delete me;
    if (src)
      delete src;
  }

  int Run()
  {
    MateriaSource* src = new MateriaSource();
    Character* me = NULL;

    if (PromptLearnMateria(src) ||
        PromptCharacter(&me))
    {
      cleanup(me, src);
      return EXIT_FAILURE;
    }
    Character* bob = new Character("bob");
    int exit_code = PromptCharacterActions(me, bob, src);
    cleanup(me, src);
    delete bob;
    return exit_code;
  }
} // namespace interactive

namespace noninteractive
{
  int Run()
  {
    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    return EXIT_SUCCESS;
  }
} // namespace noninteractive

int main(int argc, char **argv)
{
  if (argc == 1)
    return noninteractive::Run();
  else if (argc == 2 && argv[1] == std::string("-i"))
  {
    return interactive::Run();
  }
  else
    return EXIT_FAILURE;
}
