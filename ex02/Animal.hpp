/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:36:45 by htsang            #+#    #+#             */
/*   Updated: 2023/09/15 20:21:43 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Animal
{
  public:
    virtual Animal &operator=(const Animal &op);
    virtual ~Animal();

    std::string getType() const;
    virtual void makeSound() const = 0;
  
  protected:
    Animal();
    Animal(std::string type);
    Animal(const Animal &copy);

    std::string type;
};
