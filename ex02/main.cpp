/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/09/14 21:20:43 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
  FragTrap fragtrap("hello");

  fragtrap.attack("enemy");
  fragtrap.takeDamage(5);
  fragtrap.beRepaired(5);
  fragtrap.highFivesGuys();
  fragtrap.takeDamage(10);
  fragtrap.takeDamage(100);
  fragtrap.beRepaired(100);
  fragtrap.attack("enemy");
  fragtrap.takeDamage(5);
  fragtrap.beRepaired(5);
  fragtrap.takeDamage(10);
  fragtrap.highFivesGuys();
  fragtrap.takeDamage(100);
  fragtrap.beRepaired(100);
  return 0;
}
