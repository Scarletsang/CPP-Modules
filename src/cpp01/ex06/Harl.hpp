/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:59:32 by htsang            #+#    #+#             */
/*   Updated: 2023/07/21 20:45:09 by htsang           ###   ########.fr       */
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
      Harl() {};
      ~Harl() {};
      Harl(const Harl& harl) {(void) harl; };
      Harl& operator=(const Harl& harl);

      void  complain(const std::string &level) const;

    private:
      enum  level
      {
        kDebug,
        kInfo,
        kWarning,
        kError,
        kUndefined
      };

      enum  level level_to_enum(const std::string &level) const;

      void  debug() const;
      void  info() const;
      void  warning() const;
      void  error() const;
  };

} // namespace my

#endif