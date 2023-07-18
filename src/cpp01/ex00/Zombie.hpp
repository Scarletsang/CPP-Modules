/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:17:34 by htsang            #+#    #+#             */
/*   Updated: 2023/07/18 21:34:26 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

namespace my
{
  class Zombie
  {
    public:
      Zombie();
      Zombie(std::string name);
      ~Zombie();
      Zombie(const Zombie &zombie);
      Zombie&     operator=(const Zombie &zombie);

      void        announce() const;

    private:
      std::string name_;
  };

  Zombie* newZombie(std::string name);
  void    randomChump(std::string name);
} // namespace my

#endif