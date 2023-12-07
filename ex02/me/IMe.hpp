/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMe.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:49:53 by htsang            #+#    #+#             */
/*   Updated: 2023/12/07 20:20:30 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>

class IMe
{
  public:
    virtual ~IMe() {};

    virtual int&        operator[](size_t position) = 0;
    virtual const int&  operator[](size_t position) const = 0;

    virtual bool    empty() const = 0;
    virtual size_t  size() const = 0;
    virtual int     back() const = 0;

    virtual void    push_back(int value) = 0;
    virtual int     pop_back() = 0;
    virtual int     insert(size_t position, int value) = 0;
    virtual int     erase(size_t position) = 0;
    virtual void    clear() = 0;
};
