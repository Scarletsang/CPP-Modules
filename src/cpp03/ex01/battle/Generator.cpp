/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Generator.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:04:53 by htsang            #+#    #+#             */
/*   Updated: 2023/09/19 12:37:28 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Generator.hpp"

#include <iostream>
#include <iomanip>

Generator::Generator() : index_(0) {}

Generator::Generator(const Generator& value) : index_(value.index_) {}

const Generator& Generator::operator=(const Generator& value)
{
  index_ = value.index_;
  return *this;
}
