/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:39:29 by htsang            #+#    #+#             */
/*   Updated: 2023/07/19 11:02:08 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

# include <string>

class HumanB
{
  public:
    HumanB(std::string name) : name_(name), weapon_(NULL) {};
    ~HumanB() {};
    HumanB(const HumanB& human) : name_(human.name_), weapon_(human.weapon_) {};
    const HumanB& operator=(const HumanB& human);

  void  setWeapon(Weapon& weapon);
  void  attack() const;

  private:
    std::string name_;
    Weapon      *weapon_;
};

#endif