/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:22:54 by htsang            #+#    #+#             */
/*   Updated: 2023/10/28 19:23:07 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t  Serializer::serialize(Data* raw)
{
  return (reinterpret_cast<uintptr_t>(raw));
}

Data*      Serializer::deserialize(uintptr_t raw)
{
  return (reinterpret_cast<Data*>(raw));
}
