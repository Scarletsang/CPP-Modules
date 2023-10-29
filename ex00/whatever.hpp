/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:49:16 by htsang            #+#    #+#             */
/*   Updated: 2023/10/29 18:52:52 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void  swap(T &a, T &b)
{
  T tmp = a;
  a = b;
  b = tmp;
}

template <typename T>
T&  min(T& a, T& b)
{
  return (a < b) ? a : b;
}

template <typename T>
T&  max(T& a, T& b)
{
  return (a > b) ? a : b;
}
