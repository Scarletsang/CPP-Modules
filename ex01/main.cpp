/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/09/14 20:53:31 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
  ScavTrap scavtrap("hello");

  scavtrap.attack("enemy");
  scavtrap.takeDamage(5);
  scavtrap.beRepaired(5);
  scavtrap.guardGate();
  scavtrap.takeDamage(10);
  scavtrap.takeDamage(100);
  scavtrap.beRepaired(100);
  scavtrap.attack("enemy");
  scavtrap.takeDamage(5);
  scavtrap.beRepaired(5);
  scavtrap.takeDamage(10);
  scavtrap.guardGate();
  scavtrap.takeDamage(100);
  scavtrap.beRepaired(100);
  return 0;
}
