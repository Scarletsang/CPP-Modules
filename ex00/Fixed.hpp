/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:38:07 by htsang            #+#    #+#             */
/*   Updated: 2023/07/22 21:20:25 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
  public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed& fixed);
    const Fixed& operator=(const Fixed& fixed);

    int   getRawBits() const;
    void  setRawBits(int const raw);
  
  private:
    int              value_;
    static const int bits_ = 8;
};

#endif
