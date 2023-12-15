/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AvatorPrinter.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:01:18 by htsang            #+#    #+#             */
/*   Updated: 2023/09/19 20:54:40 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Generator.hpp"
#include "../ClapTrap.hpp"

#include <iostream>

class AvatorPrinter : public Generator
{
  public:
    enum  Type
    {
      kClapTrap,
      kScavTrap,
      kFragTrap,
      kDiamondTrap
    };

    AvatorPrinter();
    AvatorPrinter(Type avator_type);
    AvatorPrinter(const AvatorPrinter& value);
    ~AvatorPrinter();
    const AvatorPrinter& operator=(const AvatorPrinter& value);

    int   next();
    bool  isEnd() const;

    int   clapTrapNext();
    int   scavTrapNext();
    int   fragTrapNext();
    int   diamondTrapNext();
  
  private:
    Type  avator_type_;
};
