/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/09/15 19:10:10 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
  DiamondTrap diamondTrap("diamondTrap");

  diamondTrap.attack("target");
  diamondTrap.takeDamage(10);
  diamondTrap.beRepaired(10);
  diamondTrap.whoAmI();
  diamondTrap.guardGate();
  diamondTrap.highFivesGuys();
  diamondTrap.whoAmI();
  return 0;
}
