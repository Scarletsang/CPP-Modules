/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:39:39 by htsang            #+#    #+#             */
/*   Updated: 2023/09/15 20:41:29 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

#include <string>

class Character : public ICharacter
{
  public:
    Character();
    Character(std::string name);
    Character(const Character &copy);
    ~Character();
    Character &operator=(const Character &op);

    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);

  private:
    std::string name_;
    AMateria *inventory_[4];
};
