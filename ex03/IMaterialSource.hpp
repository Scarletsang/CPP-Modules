/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMaterialSource.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:34:26 by htsang            #+#    #+#             */
/*   Updated: 2023/09/15 20:35:02 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

#include <string>

class IMateriaSource
{
  public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};
