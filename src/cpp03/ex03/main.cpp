/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/09/19 22:08:20 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "battle/Battle.hpp"

#include <unistd.h>
#include <cstdlib>

#include <cstdlib>
#include <iostream>
#include <iomanip>

namespace interactive
{
  int  PromptName(std::string& name)
  {
    std::cout << "Enter your name (max 10 characters): ";
    std::getline(std::cin, name);
    while (std::cin.good())
    {
      if (name.length() > 10)
        std::cout << "Name too long, try again: ";
      else
        return EXIT_SUCCESS;
      std::getline(std::cin, name);
    }
    return EXIT_FAILURE;
  }

  int  PromptAction(Battle &battle)
  {
    std::string action;
  
    std::cout << "Enter your action (A/R): ";
    std::getline(std::cin, action);
    while (std::cin.good())
    {
      if (action != "A" && action != "R")
        std::cout << "Invalid action, try again: ";
      else
      {
        battle.printTurn();
        if (action == "A")
          battle.attack();
        else
          battle.repair();
        return EXIT_SUCCESS;
      }
      std::getline(std::cin, action);
    }
    return EXIT_FAILURE;
  }

  int PromptCharacter(AvatorPrinter::Type& type)
  {
    std::string character;
    AvatorPrinter scav_avator(AvatorPrinter::kScavTrap);
    AvatorPrinter frag_avator(AvatorPrinter::kFragTrap);
    AvatorPrinter diamond_avator(AvatorPrinter::kDiamondTrap);

    while (!scav_avator.isEnd() && !frag_avator.isEnd() && !diamond_avator.isEnd())
    {
      scav_avator.next();
      std::cout << std::setw(10) << "";
      frag_avator.next();
      std::cout << std::setw(10) << "";
      diamond_avator.next();
      std::cout << std::endl;
    }
    std::cout << "  scavtrap (S)"<< std::setw(15) << "" << "fragtrap (F)" << std::setw(15) << "" <<"diamondtrap (D)" << std::endl;
    std::cout << "Choose your character (F/S/D): ";
    std::getline(std::cin, character);
    while (std::cin.good())
    {
      if (character != "F" && character != "S" && character != "D")
        std::cout << "Invalid character, try again: ";
      else
      {
        if (character == "F")
          type = AvatorPrinter::kFragTrap;
        else if (character == "S")
          type = AvatorPrinter::kScavTrap;
        else if (character == "D")
          type = AvatorPrinter::kDiamondTrap;
        return EXIT_SUCCESS;
      }
      std::getline(std::cin, character);
    }
    return EXIT_FAILURE;
  }

  int CreateCharacter(std::string player_name, AvatorPrinter::Type type, ClapTrap **player)
  {
    if (type == AvatorPrinter::kScavTrap)
      *player = new ScavTrap(player_name);
    else if (type == AvatorPrinter::kFragTrap)
      *player = new FragTrap(player_name);
    else if (type == AvatorPrinter::kDiamondTrap)
      *player = new DiamondTrap(player_name);
    if (*player == NULL)
    {
      std::cerr << "Failed to create player" << std::endl;
      return EXIT_FAILURE;
    }
    else
      return EXIT_SUCCESS;
  }

  int CreateBattle(std::string player_name,
                   AvatorPrinter::Type player_type,
                   Battle &battle,
                   ClapTrap **player,
                   ClapTrap **opponent)
  {
    CreateCharacter(player_name, player_type, player);
    int dice = rand() % 3;
    AvatorPrinter::Type opponent_type = AvatorPrinter::kClapTrap;
    if (dice == 0)
    {
      CreateCharacter("Frag dude", AvatorPrinter::kFragTrap, opponent);
      opponent_type = AvatorPrinter::kFragTrap;
    }
    else if (dice == 1)
    {
      CreateCharacter("Scav dude", AvatorPrinter::kScavTrap, opponent);
      opponent_type = AvatorPrinter::kScavTrap;
    }
    else
    {
      CreateCharacter("Diamond", AvatorPrinter::kDiamondTrap, opponent);
      opponent_type = AvatorPrinter::kDiamondTrap;
    }
    if (!*opponent || !*player)
    {
      std::cerr << "Failed to create opponent" << std::endl;
      if (*opponent)
        delete *opponent;
      if (*player)
        delete *player;
      return EXIT_FAILURE;
    }
    battle = Battle(*player, *opponent, player_type, opponent_type);
    return EXIT_SUCCESS;
  }

  int Run()
  {
    Battle    battle;
    ClapTrap  *player = NULL;
    ClapTrap  *opponent = NULL;
    {
      std::string         player_name;
      AvatorPrinter::Type player_type;

      if (PromptCharacter(player_type) ||
          PromptName(player_name) ||
          CreateBattle(player_name, player_type, battle, &player, &opponent))
        return EXIT_FAILURE;
    }
    battle.configure(60, 3, 23, 35);
    while (!battle.isEnd() && std::cin.good())
    {
      if (PromptAction(battle))
      {
        delete player;
        delete opponent;
        return EXIT_FAILURE;
      }
      battle.print();
      std::cout << "Opponent deciding moves..." << std::endl << std::endl;
      sleep(1);
      battle.printTurn();
      battle.randomAction();
      battle.print();
    }
    battle.printWinner();
    delete player;
    delete opponent;
    return EXIT_SUCCESS;
  }
} // namespace battle

namespace noninteractive
{
  int Run()
  {
    DiamondTrap diamondTrap("diamondTrap");

    diamondTrap.attack("target");
    diamondTrap.takeDamage(10);
    diamondTrap.beRepaired(10);
    diamondTrap.whoAmI();
    diamondTrap.guardGate();
    diamondTrap.highFivesGuys();
    diamondTrap.whoAmI();
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
