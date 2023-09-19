/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:08:40 by htsang            #+#    #+#             */
/*   Updated: 2023/09/19 20:45:23 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
  public:
    static const int kDefaultHitPoints = 100;
    static const int kDefaultEnergyPoints = 100;
    static const int kDefaultAttackDamage = 30;

    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap& copy);
    ~FragTrap();
    FragTrap& operator=(const FragTrap& copy);

    void  highFivesGuys();
};
