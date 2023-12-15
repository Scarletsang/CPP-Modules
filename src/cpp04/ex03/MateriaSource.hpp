/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 22:34:59 by htsang            #+#    #+#             */
/*   Updated: 2023/09/19 23:24:23 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

#include <string>

class MateriaSource : public IMateriaSource
{
  public:
    MateriaSource();
    MateriaSource(const MateriaSource &copy);
    ~MateriaSource();
    MateriaSource &operator=(const MateriaSource &materiaSource);

    void      learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);

    void  print() const;

  private:
    AMateria* materias_[4];
};
