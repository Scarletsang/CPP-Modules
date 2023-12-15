/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:42:24 by htsang            #+#    #+#             */
/*   Updated: 2023/09/15 20:09:16 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

#include "Brain.hpp"

class Cat : public Animal
{
  public:
    Cat();
    Cat(const Cat &copy);
    ~Cat();
    Cat &operator=(const Cat &cat);

    void makeSound() const;
  
  private:
    Brain *brain_;
};
