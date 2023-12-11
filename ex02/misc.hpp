/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 02:40:52 by htsang            #+#    #+#             */
/*   Updated: 2023/12/11 15:18:11 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <utility>
#include <iostream>

template <typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p)
{
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}

template <typename T>
const T&  Print(const std::string& title, const T& container)
{
  std::cout << title << ": ";
  for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
  return container;
}
