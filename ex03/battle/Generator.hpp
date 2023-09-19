/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Generator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:54:18 by htsang            #+#    #+#             */
/*   Updated: 2023/09/19 19:26:58 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Generator
{
  public:
    Generator();
    Generator(const Generator& value);
    const Generator& operator=(const Generator& value);
    virtual ~Generator() {}

    virtual int next() = 0;
    virtual bool isEnd() const = 0;
  
  protected:
    int index_;
};
