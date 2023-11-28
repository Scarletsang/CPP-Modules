/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:50:11 by htsang            #+#    #+#             */
/*   Updated: 2023/11/28 15:56:14 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <utility>

template <typename T>
std::pair<int, int> easyfind(T container, int n)
{
  typename T::iterator it = std::find(container.begin(), container.end(), n);
  if (it == container.end())
    return std::make_pair(0, -1);
  return std::make_pair(n, std::distance(container.begin(), it));
}
