/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AvatorPrinter.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:01:18 by htsang            #+#    #+#             */
/*   Updated: 2023/09/19 12:08:54 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Generator.hpp"

#include <iostream>

class AvatorPrinter : public Generator
{
  public:
    AvatorPrinter();
    AvatorPrinter(const AvatorPrinter& value);
    ~AvatorPrinter();
    const AvatorPrinter& operator=(const AvatorPrinter& value);

    int   next();
    bool  isEnd() const;
};
