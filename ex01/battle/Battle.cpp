/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Battle.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:07:51 by htsang            #+#    #+#             */
/*   Updated: 2023/09/19 13:44:03 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Battle.hpp"
#include "../ClapTrap.hpp"
#include "AvatorPrinter.hpp"
#include "StatusPrinter.hpp"

#include <iostream>
#include <iomanip>

Battle::Battle(ClapTrap& player1,
               ClapTrap& player2,
               int low_health,
               int chance_to_attack,
               int repair_lower_bound,
               int repair_upper_bound)
  : player1_(player1),
    player2_(player2),
    turn_(0),
    low_health_(low_health),
    chance_to_attack_(chance_to_attack),
    repair_lower_bound_(repair_lower_bound),
    repair_upper_bound_(repair_upper_bound)
{
  srand(time(NULL));
}

Battle::Battle(const Battle& value)
  : player1_(value.player1_),
    player2_(value.player2_),
    turn_(value.turn_),
    low_health_(value.low_health_),
    chance_to_attack_(value.chance_to_attack_),
    repair_lower_bound_(value.repair_lower_bound_),
    repair_upper_bound_(value.repair_upper_bound_)
{
  srand(time(NULL));
}

Battle::~Battle(){}

const Battle& Battle::operator=(const Battle& value)
{
  player1_ = value.player1_;
  player2_ = value.player2_;
  turn_ = value.turn_;
  return *this;
}

void  Battle::attack()
{
  if (turn_ % 2 == 0)
  {
    player1_.attack(player2_.getName());
    player2_.takeDamage(player1_.getAttackDamage());
  }
  else
  {
    player2_.attack(player1_.getName());
    player1_.takeDamage(player2_.getAttackDamage());
  }
  turn_++;
}

void  Battle::repair()
{
  getCurrentPlayer().beRepaired(getRandomNumber(repair_lower_bound_, repair_upper_bound_));
  turn_++;
}

void  Battle::randomAction()
{
  int number;
  if (getCurrentPlayer().getHitPoints() <= low_health_)
    number = getRandomNumber(0, chance_to_attack_);
  else
    number = getRandomNumber(0, 1);
  if (number == 0)
    attack();
  else
    repair();
}

bool  Battle::isEnd() const
{
  return player1_.getHitPoints() <= 0 || \
         player2_.getHitPoints() <= 0 || \
         player1_.getEnergyPoints() <= 0 || \
         player2_.getEnergyPoints() <= 0;
}

void  Battle::print()
{
  {
    AvatorPrinter  avator1;
    AvatorPrinter  avator2;
    while (!avator1.isEnd() && !avator2.isEnd())
    {
      avator1.next();
      std::cout << std::setw(10) << "";
      avator2.next();
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;
  {
    StatusPrinter  status1(player1_);
    StatusPrinter  status2(player2_);
    while (!status1.isEnd() && !status2.isEnd())
    {
      status1.next();
      std::cout << std::setw(10) << "";
      status2.next();
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;
}

void  Battle::printWinner() const
{
  if (player1_.getHitPoints() <= 0)
    std::cout << player2_.getName() << " won!" << std::endl;
  else if (player2_.getHitPoints() <= 0)
    std::cout << player1_.getName() << " won!" << std::endl;
  else
    std::cout << "Draw!" << std::endl;
}

void  Battle::printTurn() const
{
  std::cout << std::endl;
  std::cout << std::setw(19) << "" << "Turn " << turn_ << std::endl << std::endl;
}

int  Battle::getRandomNumber(int min, int max) const
{
  return rand() % (max - min + 1) + min;
}

ClapTrap& Battle::getCurrentPlayer()
{
  if (turn_ % 2 == 0)
    return player1_;
  else
    return player2_;
}
