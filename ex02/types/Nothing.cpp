/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nothing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:12:07 by htsang            #+#    #+#             */
/*   Updated: 2023/12/08 14:12:52 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Nothing.hpp"

Nothing::Nothing() {}

Nothing::Nothing(const Nothing& other) { (void) other; }

Nothing::~Nothing() {}

Nothing& Nothing::operator=(const Nothing&)
{
  return *this;
}

bool  Nothing::operator==(const Nothing&) const
{
  return true;
}

bool  Nothing::operator!=(const Nothing&) const
{
  return false;
}
