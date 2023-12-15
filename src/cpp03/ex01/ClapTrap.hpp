/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:06:57 by htsang            #+#    #+#             */
/*   Updated: 2023/09/19 13:05:23 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ClapTrap
{
  public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(int hit_points, int energy_points, int attack_damage);
    ClapTrap(std::string name, int hit_points, int energy_points, int attack_damage);
    ClapTrap(const ClapTrap& copy);
    ~ClapTrap();
    ClapTrap& operator=(const ClapTrap& copy);

    void  attack(const std::string& target);
    void  beRepaired(unsigned int amount);
    void  takeDamage(unsigned int amount);

    std::string getName() const;
    int         getHitPoints() const;
    int         getEnergyPoints() const;
    int         getAttackDamage() const;

  protected:
    bool  isActive(const char *action) const;

    std::string name_;
    int hit_points_;
    int energy_points_;
    int attack_damage_;
};
