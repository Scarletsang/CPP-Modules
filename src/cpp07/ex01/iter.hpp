/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:59:30 by htsang            #+#    #+#             */
/*   Updated: 2023/11/02 14:00:38 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>

template <typename T>
void iter(T *array, size_t length, void (*f)(T const &))
{
  for (size_t i = 0; i < length; i++)
    f(array[i]);
}
