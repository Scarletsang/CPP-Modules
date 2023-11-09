/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:01:32 by htsang            #+#    #+#             */
/*   Updated: 2023/11/09 21:18:50 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <set>

class Span
{
  public:
    static const unsigned int kDefaultSize = 100;
    Span();
    Span(unsigned int n);
    Span(const Span& copy);
    ~Span();

    Span& operator=(const Span& copy);

    void  addNumber(int n);
    int   shortestSpan() const;
    int   longestSpan() const;
  
  private:
    unsigned int   maximum_size_;
    std::set<int>  numbers_;
};
