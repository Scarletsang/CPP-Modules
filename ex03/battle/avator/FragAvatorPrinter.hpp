/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragAvatorPrinter.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:01:18 by htsang            #+#    #+#             */
/*   Updated: 2023/09/19 14:54:28 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../AvatorPrinter.hpp"

#include <iostream>

class FragAvatorPrinter : public AvatorPrinter
{
  public:
    FragAvatorPrinter();
    FragAvatorPrinter(const FragAvatorPrinter& value);
    ~FragAvatorPrinter();
    const FragAvatorPrinter& operator=(const FragAvatorPrinter& value);

    int   next();
    bool  isEnd() const;
};
