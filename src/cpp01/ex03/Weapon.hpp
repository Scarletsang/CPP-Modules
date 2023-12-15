/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 02:54:38 by htsang            #+#    #+#             */
/*   Updated: 2023/07/19 11:02:39 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
  public:
    Weapon() : type_("") {};
    Weapon(std::string type) : type_(type) {};
    ~Weapon() {};
    Weapon(const Weapon& weapon);
    const Weapon& operator=(const Weapon& weapon);

    const std::string& getType() const;
    void setType(std::string type);

  private:
    std::string type_;
};

#endif