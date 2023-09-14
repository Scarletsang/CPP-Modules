/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/09/14 20:44:39 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
  ClapTrap claptrap("hello");

  claptrap.attack("enemy");
  claptrap.takeDamage(5);
  claptrap.beRepaired(5);
  claptrap.takeDamage(10);
  claptrap.takeDamage(100);
  claptrap.beRepaired(100);
  claptrap.attack("enemy");
  claptrap.takeDamage(5);
  claptrap.beRepaired(5);
  claptrap.takeDamage(10);
  claptrap.takeDamage(100);
  claptrap.beRepaired(100);
  return 0;
}
