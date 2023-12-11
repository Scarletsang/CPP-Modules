/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InsertionPositions.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 00:31:56 by htsang            #+#    #+#             */
/*   Updated: 2023/12/11 01:41:32 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InsertionPositions.hpp"

#include "Maybe.hpp"
#include "JacobsthalSequence.hpp"

InsertionPositions::InsertionPositions()
  : sequence_(), position_()
{
  sequence_.next();
  last_jacobsthal_ = sequence_.next();
  jacobsthal_ = sequence_.next();
}

InsertionPositions::InsertionPositions(const InsertionPositions& other)
  : sequence_(other.sequence_),
    position_(other.position_),
    jacobsthal_(other.jacobsthal_),
    last_jacobsthal_(other.last_jacobsthal_) {}

InsertionPositions::~InsertionPositions() {}

InsertionPositions& InsertionPositions::operator=(const InsertionPositions& other)
{
  if (this != &other)
  {
    sequence_ = other.sequence_;
    position_ = other.position_;
    jacobsthal_ = other.jacobsthal_;
    last_jacobsthal_ = other.last_jacobsthal_;
  }
  return *this;
}

Maybe<int>  InsertionPositions::next()
{
  if (position_.is_ok() && position_.value() - 1 > last_jacobsthal_)
  {
    position_ = position_.value() - 1;
  }
  else
  {
    last_jacobsthal_ = jacobsthal_;
    jacobsthal_ = sequence_.next();
    position_ = jacobsthal_;
  }
  if (position_.value() < 0)
    return Nothing();
  return position_;
}

void  InsertionPositions::reset()
{
  last_jacobsthal_ = 3;
  position_ = 1;
}
