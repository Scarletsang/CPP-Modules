/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JacobsthalSequence.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 00:31:22 by htsang            #+#    #+#             */
/*   Updated: 2023/12/11 03:46:53 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>

#include "Maybe.hpp"

class JacobsthalSequence
{
  public:
    JacobsthalSequence();
    JacobsthalSequence(const JacobsthalSequence& other);
    ~JacobsthalSequence();

    JacobsthalSequence& operator=(const JacobsthalSequence& other);
    size_t next();

  private:
    Maybe<size_t> a;
    Maybe<size_t> b;
};
