/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 23:31:15 by htsang            #+#    #+#             */
/*   Updated: 2023/10/27 23:41:58 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

namespace convert
{
  Type Type::Normal() { return Type(kNormal); }
  Type Type::Nan() { return Type(kNan); }
  Type Type::PositiveInfinity() { return Type(kPositiveInfinity); }
  Type Type::NegativeInfinity() { return Type(kNegativeInfinity); }
  Type::Type(enum Value value) : value(value) {}
} // namespace convert
