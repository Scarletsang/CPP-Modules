/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InsertionPositions.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 00:31:56 by htsang            #+#    #+#             */
/*   Updated: 2023/12/11 01:34:33 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Maybe.hpp"
#include "JacobsthalSequence.hpp"

class InsertionPositions
{
  public:
    InsertionPositions();
    InsertionPositions(const InsertionPositions& other);
    ~InsertionPositions();

    InsertionPositions& operator=(const InsertionPositions& other);
    Maybe<int>          next();
    void                reset();

  private:
    JacobsthalSequence sequence_;
    Maybe<int>         position_;
    int                jacobsthal_;
    int                last_jacobsthal_;
};
