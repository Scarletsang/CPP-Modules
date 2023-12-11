/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nothing.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:10:19 by htsang            #+#    #+#             */
/*   Updated: 2023/12/11 00:55:16 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Nothing
{
  public:
    Nothing();
    Nothing(const Nothing& other);
    ~Nothing();
    Nothing& operator=(const Nothing& other);

    bool  operator==(const Nothing& other) const;
    bool  operator!=(const Nothing& other) const;

    template <typename T>
    bool  operator==(const T& other) const;

    template <typename T>
    bool  operator!=(const T& other) const;
};

template <typename T>
bool  Nothing::operator==(const T&) const
{
  return false;
}

template <typename T>
bool  Nothing::operator!=(const T&) const
{
  return true;
}

std::ostream& operator<<(std::ostream& os, const Nothing& nothing);
