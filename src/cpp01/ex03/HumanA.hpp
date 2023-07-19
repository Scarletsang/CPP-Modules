/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 03:20:20 by htsang            #+#    #+#             */
/*   Updated: 2023/07/19 11:01:41 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

# include <string>

class HumanA
{
  public:
    HumanA(std::string name, Weapon& weapon) : name_(name), weapon_(weapon) {};
    ~HumanA() {};
    HumanA(const HumanA& humanA) : name_(humanA.name_), weapon_(humanA.weapon_) {};
    HumanA& operator=(const HumanA& humanA);

    void attack() const;

  private:
    std::string   name_;
    Weapon& weapon_;
};

#endif