/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Battle.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:04:04 by htsang            #+#    #+#             */
/*   Updated: 2023/09/19 12:43:01 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../ClapTrap.hpp"

#include <cstdlib>

class Battle
{
  public:
    Battle(ClapTrap& player1, ClapTrap& player2);
    Battle(const Battle& value);
    ~Battle();
    const Battle& operator=(const Battle& value);

    void  attack();
    void  repair();
    void  randomAction();

    bool  isEnd() const;

    void  print();
    void  printWinner() const;

  private:
    Battle();
    int   getRandomNumber(int min, int max) const;

    ClapTrap& player1_;
    ClapTrap& player2_;
    int       turn_;
};
