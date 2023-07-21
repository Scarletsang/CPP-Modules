/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:27:02 by htsang            #+#    #+#             */
/*   Updated: 2023/07/18 21:27:25 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <string>

namespace my
{
  Zombie* newZombie(std::string name)
  {
    Zombie *zombie = new Zombie(name);
    return (zombie);
  }
} // namespace my