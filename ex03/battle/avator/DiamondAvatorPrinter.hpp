/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondAvatorPrinter copy.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:01:18 by htsang            #+#    #+#             */
/*   Updated: 2023/09/19 14:03:58 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../AvatorPrinter.hpp"

#include <iostream>

class DiamondAvatorPrinter : public AvatorPrinter
{
  public:
    DiamondAvatorPrinter();
    DiamondAvatorPrinter(const DiamondAvatorPrinter& value);
    ~DiamondAvatorPrinter();
    const DiamondAvatorPrinter& operator=(const DiamondAvatorPrinter& value);

    int   next();
    bool  isEnd() const;
};
