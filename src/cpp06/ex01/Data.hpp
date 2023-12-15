/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:11:32 by htsang            #+#    #+#             */
/*   Updated: 2023/10/28 19:30:55 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Data
{
  public:
    Data();
    Data(int x, int y);
    Data(Data const& src);
    ~Data();

    Data& operator=(Data const& rhs);

    int x() const;
    int y() const;

  private:
    int location_x;
    int location_y;
};

std::ostream& operator<<(std::ostream& os, Data const& rhs);
