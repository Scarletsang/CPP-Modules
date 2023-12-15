/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:58:31 by htsang            #+#    #+#             */
/*   Updated: 2023/07/19 11:07:36 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

#include <cstdlib>

#include <string>

int main(void)
{
  {
    Weapon  club = Weapon("crude spiked club");
    HumanA  bob("Bob", club);

    bob.attack();
    club.setType("strip club");
    bob.attack();
  }
  {
    Weapon  club = Weapon("crude spiked club");
    HumanB  jim("Jim");

    jim.attack();
    jim.setWeapon(club);
    jim.attack();
    club.setType("strip club");
    jim.attack();
  }

  return EXIT_SUCCESS;
}
