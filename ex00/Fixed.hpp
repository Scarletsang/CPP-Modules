/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:38:07 by htsang            #+#    #+#             */
/*   Updated: 2023/09/14 19:43:57 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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
