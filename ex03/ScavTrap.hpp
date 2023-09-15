/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:47:30 by htsang            #+#    #+#             */
/*   Updated: 2023/09/15 18:59:24 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
  public:
    static const int kDefaultHitPoints = 100;
    static const int kDefaultEnergyPoints = 50;
    static const int kDefaultAttackDamage = 20;

    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& copy);
    ~ScavTrap();
    ScavTrap& operator=(const ScavTrap& copy);

    void  attack(const std::string& target);
    void  guardGate();
};
