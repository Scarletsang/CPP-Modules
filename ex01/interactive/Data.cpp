/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:54:00 by htsang            #+#    #+#             */
/*   Updated: 2023/12/04 22:21:45 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

namespace interactive
{
  Data::Data() {}

  Data::Data(const Data&) {}

  Data::~Data() {}

  const Data& Data::operator=(const Data&)
  {
    return *this;
  }

} // namespace interactive

