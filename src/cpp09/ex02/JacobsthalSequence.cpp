/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JacobsthalSequence.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 00:31:22 by htsang            #+#    #+#             */
/*   Updated: 2023/12/11 03:47:15 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "JacobsthalSequence.hpp"

#include <cstdlib>

JacobsthalSequence::JacobsthalSequence()
  : a(), b() {}

JacobsthalSequence::JacobsthalSequence(const JacobsthalSequence& other)
  : a(other.a), b(other.b) {}

JacobsthalSequence::~JacobsthalSequence() {}

JacobsthalSequence& JacobsthalSequence::operator=(const JacobsthalSequence& other)
{
  if (this != &other)
  {
    a = other.a;
    b = other.b;
  }
  return *this;
}

size_t JacobsthalSequence::next()
{
  if (!a.is_ok())
  {
    a = 0;
    return 0;
  }
  else if (!b.is_ok())
  {
    b = 1;
    return 1;
  }
  int c = b.value() + 2 * a.value();
  a = b;
  b = c;
  return c;
}
