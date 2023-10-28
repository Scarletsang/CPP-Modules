/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 23:31:15 by htsang            #+#    #+#             */
/*   Updated: 2023/10/28 17:11:53 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

namespace converter
{
  ScalarType ScalarType::Normal() { return ScalarType(kNormal); }
  ScalarType ScalarType::Nan() { return ScalarType(kNan); }
  ScalarType ScalarType::PositiveInfinity() { return ScalarType(kPositiveInfinity); }
  ScalarType ScalarType::NegativeInfinity() { return ScalarType(kNegativeInfinity); }
  ScalarType::ScalarType(enum Value value) : value(value) {}
} // namespace convert
