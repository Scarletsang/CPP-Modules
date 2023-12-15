/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:09:18 by htsang            #+#    #+#             */
/*   Updated: 2023/07/21 20:04:38 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>
#include <string>

namespace karin
{
  Harl::Harl()
  {
    complain_func_[0] = &Harl::debug;
    complain_func_[1] = &Harl::info;
    complain_func_[2] = &Harl::warning;
    complain_func_[3] = &Harl::error;
  }

  Harl& Harl::operator=(const Harl& harl)
  {
    (void) harl;
    return (*this);
  }

  void  Harl::complain(std::string level)
  {
    for (int i = 0; i < 4; i++)
    {
      if (level == complain_levels_[i])
      {
        (this->*complain_func_[i])();
        break ;
      }
    }
  }

  std::string Harl::complain_levels_[4] = {"debug", "info", "warning", "error"};

  void  Harl::debug()
  {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
  }

  void  Harl::info()
  {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
  }

  void  Harl::warning()
  {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming foryears whereas you started working here since last month." << std::endl;
  }

  void  Harl::error()
  {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
  }

} // namespace my
