/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:06:11 by htsang            #+#    #+#             */
/*   Updated: 2023/11/24 20:52:32 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <cstdlib>

#include <limits>
#include <stdexcept>
#include <set>
#include <algorithm>
#include <iterator>

Span::Span()
  : maximum_size_(kDefaultSize) {}

Span::Span(unsigned int n)
  : maximum_size_(n) {}

Span::Span(const Span& copy)
  : maximum_size_(copy.maximum_size_),
    numbers_(copy.numbers_) {}

Span::~Span() {}

Span& Span::operator=(const Span& copy)
{
  if (this == &copy)
    return *this;
  maximum_size_ = copy.maximum_size_;
  numbers_ = copy.numbers_;
  return *this;
}

void  Span::addNumber(int n)
{
  if (numbers_.size() == maximum_size_)
    throw std::runtime_error("Container is full");
  numbers_.insert(n);
}

int Span::shortestSpan() const
{
  if (numbers_.size() < 2)
    throw std::runtime_error("Container must have at least 2 elements");
  int span = std::numeric_limits<int>::max();
  for (std::multiset<int>::iterator it = numbers_.begin(); it != --numbers_.end();)
    span = std::min(span, abs(*it - *(++it)));
  return span;
}

int Span::longestSpan() const
{
  if (numbers_.size() < 2)
    throw std::runtime_error("Container must have at least 2 elements");
  return abs(*numbers_.begin() - *--numbers_.end());
}
