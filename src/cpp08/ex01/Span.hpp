/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:01:32 by htsang            #+#    #+#             */
/*   Updated: 2023/12/04 22:19:10 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <set>
#include <iterator>

class Span
{
  public:
    static const unsigned int kDefaultSize = 100;
    typedef std::multiset<int>::const_iterator const_iterator;
    Span();
    Span(unsigned int n);
    Span(const Span& copy);
    ~Span();

    Span& operator=(const Span& copy);

    void  addNumber(int n);

    template <typename InputIt>
    void  addNumbers(InputIt first, InputIt last);

    // iterators
    const_iterator  begin() const;
    const_iterator  end() const;
    unsigned int    capacity() const;

    int   shortestSpan() const;
    int   longestSpan() const;

  private:
    unsigned int        maximum_size_;
    std::multiset<int>  numbers_;
};

template <typename InputIt>
void  Span::addNumbers(InputIt first, InputIt last)
{
  if (std::distance(first, last) + numbers_.size() > maximum_size_)
    throw std::runtime_error("Container is full");
  numbers_.insert(first, last);
}
