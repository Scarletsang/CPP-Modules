/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JacobsthalSequence.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 00:31:22 by htsang            #+#    #+#             */
/*   Updated: 2023/12/11 01:19:29 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Maybe.hpp"

class JacobsthalSequence
{
  public:
    JacobsthalSequence();
    JacobsthalSequence(const JacobsthalSequence& other);
    ~JacobsthalSequence();

    JacobsthalSequence& operator=(const JacobsthalSequence& other);
    int next();

  private:
    Maybe<int> a;
    Maybe<int> b;
};
