/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:09:18 by htsang            #+#    #+#             */
/*   Updated: 2023/07/21 20:46:29 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>
#include <string>

namespace karin
{
  Harl& Harl::operator=(const Harl& harl)
  {
    (void) harl;
    return (*this);
  }

  void  Harl::complain(const std::string &level) const
  {
    switch (level_to_enum(level))
    {
      case Harl::kDebug:
        debug();
      case Harl::kInfo:
        info();
      case Harl::kWarning:
        warning();
      case Harl::kError:
        error();
        break;
      default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
  }

  enum  Harl::level Harl::level_to_enum(const std::string &level) const
  {
    if (level.compare("DEBUG") == 0)
      return (Harl::kDebug);
    else if (level.compare("INFO") == 0)
      return (Harl::kInfo);
    else if (level.compare("WARNING") == 0)
      return (Harl::kWarning);
    else if (level.compare("ERROR") == 0)
      return (Harl::kError);
    else
      return (Harl::kUndefined);
  }

  void  Harl::debug() const
  {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
  }

  void  Harl::info() const
  {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
  }

  void  Harl::warning() const
  {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming foryears whereas you started working here since last month." << std::endl;
  }

  void  Harl::error() const
  {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
  }

} // namespace my
