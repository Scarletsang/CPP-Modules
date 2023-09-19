/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Battle.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:04:04 by htsang            #+#    #+#             */
/*   Updated: 2023/09/19 21:35:50 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../ClapTrap.hpp"
#include "AvatorPrinter.hpp"

#include <cstdlib>

class Battle
{
  public:
    Battle();
    Battle(ClapTrap* player1,
           ClapTrap* player2,
           AvatorPrinter::Type player1_type,
           AvatorPrinter::Type player2_type);
    Battle(const Battle& value);
    ~Battle();
    const Battle& operator=(const Battle& value);

    void  configure(int low_health,
                    int chance_to_attack,
                    int repair_lower_bound,
                    int repair_upper_bound);

    void  attack();
    void  repair();
    void  randomAction();

    bool  isEnd() const;

    void  print();
    void  printWinner() const;
    void  printTurn() const;

  private:
    ClapTrap& getCurrentPlayer();
    int       getRandomNumber(int min, int max) const;

    ClapTrap*           player1_;
    ClapTrap*           player2_;
    AvatorPrinter::Type player1_type_;
    AvatorPrinter::Type player2_type_;

    int       turn_;

    int       low_health_;
    int       chance_to_attack_;
    int       repair_lower_bound_;
    int       repair_upper_bound_;
};
