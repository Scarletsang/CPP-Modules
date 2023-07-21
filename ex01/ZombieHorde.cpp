/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:47:34 by htsang            #+#    #+#             */
/*   Updated: 2023/07/18 22:36:43 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

namespace my
{
  Zombie* zombieHorde(int n, std::string name)
  {
    Zombie* zombie_horde = new Zombie[n];

    for (int i = 0; i < n; i++)
    {
      zombie_horde[i].setName(name);
    }
    return (zombie_horde);
  }
} // namespace my