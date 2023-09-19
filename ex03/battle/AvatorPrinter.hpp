/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Generator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:54:18 by htsang            #+#    #+#             */
/*   Updated: 2023/09/19 14:53:53 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class AvatorPrinter
{
  public:
    AvatorPrinter();
    AvatorPrinter(const AvatorPrinter& value);
    const AvatorPrinter& operator=(const AvatorPrinter& value);
    virtual ~AvatorPrinter() {}

    virtual int next() = 0;
    virtual bool isEnd() const = 0;
  
  protected:
    void  printCenteredText(const char* text, int width) const;

    int index_;
};
