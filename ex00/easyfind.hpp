/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:50:11 by htsang            #+#    #+#             */
/*   Updated: 2023/11/09 21:03:23 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <exception>

template <typename T>
int easyfind(T &container, int n)
{
    typename T::iterator it;
    it = std::find(container.begin(), container.end(), n);
    if (it != container.end())
        return (*it);
    else
        throw std::runtime_error("Element not found");
}
