/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:10:40 by htsang            #+#    #+#             */
/*   Updated: 2023/10/28 19:22:39 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>

#include "Data.hpp"

class Serializer
{
  public:
    static uintptr_t  serialize(Data* raw);
    static Data*      deserialize(uintptr_t raw);
  
  private:
    Serializer();
};
