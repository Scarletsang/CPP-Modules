/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 22:44:13 by htsang            #+#    #+#             */
/*   Updated: 2023/09/16 22:48:44 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
  for (int i = 0; i < 4; i++)
    materias_[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
  for (int i = 0; i < 4; i++)
  {
    if (materias_[i])
      delete materias_[i];
    materias_[i] = copy.materias_[i]->clone();
  }
}

MateriaSource::~MateriaSource()
{
  for (int i = 0; i < 4; i++)
  {
    if (materias_[i])
      delete materias_[i];
  }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource)
{
  if (this == &materiaSource)
    return (*this);
  for (int i = 0; i < 4; i++)
  {
    if (materias_[i])
      delete materias_[i];
    materias_[i] = materiaSource.materias_[i]->clone();
  }
  return (*this);
}

void MateriaSource::learnMateria(AMateria* materia)
{
  for (int i = 0; i < 4; i++)
  {
    if (!materias_[i])
    {
      materias_[i] = materia;
      return ;
    }
  }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
  for (int i = 0; i < 4; i++)
  {
    if (materias_[i] && materias_[i]->getType() == type)
      return (materias_[i]->clone());
  }
  return (NULL);
}
