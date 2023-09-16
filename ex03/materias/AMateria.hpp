/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:31:09 by htsang            #+#    #+#             */
/*   Updated: 2023/09/16 22:56:24 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

#include <string>

class AMateria
{
  public:
    AMateria();
    AMateria(std::string const & type);
    AMateria(const AMateria &copy);
    virtual ~AMateria();
    AMateria &operator=(const AMateria &op);

    std::string const & getType() const; //Returns the materia type

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
  
  protected:
    std::string type_;
};
