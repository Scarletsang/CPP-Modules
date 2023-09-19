/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavAvatorPrinter.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:01:18 by htsang            #+#    #+#             */
/*   Updated: 2023/09/19 14:54:26 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../AvatorPrinter.hpp"

#include <iostream>

class ScavAvatorPrinter : public AvatorPrinter
{
  public:
    ScavAvatorPrinter();
    ScavAvatorPrinter(const ScavAvatorPrinter& value);
    ~ScavAvatorPrinter();
    const ScavAvatorPrinter& operator=(const ScavAvatorPrinter& value);

    int   next();
    bool  isEnd() const;
};