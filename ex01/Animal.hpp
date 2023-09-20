/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:36:45 by htsang            #+#    #+#             */
/*   Updated: 2023/09/20 19:37:55 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Animal
{
  public:
    Animal();
    Animal(std::string type);
    Animal(const Animal &copy);
    virtual ~Animal();
    Animal &operator=(const Animal &op);

    std::string getType() const;
    virtual void makeSound() const;
  
  protected:
    std::string type;
};
