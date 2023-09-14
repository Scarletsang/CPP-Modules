/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:06:57 by htsang            #+#    #+#             */
/*   Updated: 2023/09/14 20:43:50 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ClapTrap
{
  public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& copy);
    ~ClapTrap();
    ClapTrap& operator=(const ClapTrap& copy);

    void  attack(const std::string& target);
    void  beRepaired(unsigned int amount);
    void  takeDamage(unsigned int amount);

  protected:
    bool  isActive(const char *action) const;

  private:
    std::string name_;
    int hit_points_;
    int energy_points_;
    int attack_damage_;
};
