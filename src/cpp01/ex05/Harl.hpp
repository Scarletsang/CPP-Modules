/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:59:32 by htsang            #+#    #+#             */
/*   Updated: 2023/07/21 19:53:42 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HARL_HPP
# define HARL_HPP

# include <string>

namespace karin
{
  class Harl
  {
    public:
      Harl();
      ~Harl() {};
      Harl(const Harl& harl) {(void) harl; };
      Harl& operator=(const Harl& harl);

      void  complain(std::string level);

    private:
      typedef void  (Harl::*ComplainFunc)();

      ComplainFunc        complain_func_[4];
      static std::string  complain_levels_[4];

      void  debug();
      void  info();
      void  warning();
      void  error();
  };

} // namespace my

#endif