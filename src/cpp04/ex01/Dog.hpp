/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:42:24 by htsang            #+#    #+#             */
/*   Updated: 2023/09/15 20:09:10 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

#include "Brain.hpp"

class Dog : public Animal
{
  public:
    Dog();
    Dog(const Dog &copy);
    ~Dog();
    Dog &operator=(const Dog &dog);

    void makeSound() const;
  
  private:
    Brain *brain_;
};
