/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 01:57:32 by htsang            #+#    #+#             */
/*   Updated: 2023/12/11 03:14:32 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <utility>
#include <memory>

#include "Maybe.hpp"
#include "Nothing.hpp"
#include "misc.hpp"

#include "InsertionPositions.hpp"

struct Range
{
  int             index;
  int             length;

  Range(int index, int length)
    : index(index), length(length) {}
};

template <template <typename, typename> class Container, template <typename> class Allocator = std::allocator>
class PMergeMe
{
  public:
    typedef std::pair<int, int>               Pair;
    typedef Container<Pair, Allocator<Pair> > PairContainer;
    typedef Container<int, Allocator<int> >   IntContainer;

    struct Sorter
    {
      IntContainer  main;
      IntContainer  pend;
    };

    PMergeMe();
    PMergeMe(const PMergeMe&);
    ~PMergeMe();
    PMergeMe& operator=(const PMergeMe&);

    IntContainer  create_ints(int argc, const char** argv);

    std::pair<PairContainer, Maybe<int> >  create_pairs(const IntContainer& ints);

    PairContainer merge(const PairContainer& pairs);
    PairContainer merge(const PairContainer& pairs, Range range);
    PairContainer merge_1(const PairContainer& pairs, Range range);
    PairContainer merge_2(const PairContainer& pairs, Range range);
    PairContainer merge_n(const PairContainer& pairs, Range range);

    Sorter  insert(const PairContainer& pairs);
};

/////////////////////////////////////////////////////
////////////   template implementation   ////////////
/////////////////////////////////////////////////////

template <template <typename, typename> class Container, template <typename> class Allocator>
PMergeMe<Container, Allocator>::PMergeMe() {}

template <template <typename, typename> class Container, template <typename> class Allocator>
PMergeMe<Container, Allocator>::PMergeMe(const PMergeMe&) {}

template <template <typename, typename> class Container, template <typename> class Allocator>
PMergeMe<Container, Allocator>::~PMergeMe() {}

template <template <typename, typename> class Container, template <typename> class Allocator>
PMergeMe<Container, Allocator>& PMergeMe<Container, Allocator>::operator=(const PMergeMe&)
{
  return *this;
}

template <template <typename, typename> class Container, template <typename> class Allocator>
typename PMergeMe<Container, Allocator>::IntContainer  PMergeMe<Container, Allocator>::create_ints(
  int argc, const char** argv)
{
  IntContainer  ints;
  for (int i = 1; i < argc; i++)
  {
    ints.push_back(std::atoi(argv[i]));
  }
  return ints;
}

template <template <typename, typename> class Container, template <typename> class Allocator>
std::pair<typename PMergeMe<Container, Allocator>::PairContainer, Maybe<int> >  PMergeMe<Container, Allocator>::create_pairs(
  const IntContainer& ints)
{
  PairContainer pairs;
  Maybe<int>    leftover;
  for (typename IntContainer::const_iterator it = ints.begin(); it != ints.end(); ++it)
  {
    if (leftover.is_ok())
    {
      if (*it < leftover.value())
        pairs.push_back(std::make_pair(leftover.value(), *it));
      else
        pairs.push_back(std::make_pair(*it, leftover.value()));
      leftover = Nothing();
    }
    else
      leftover = *it;
  }
  return std::make_pair(pairs, leftover);
}

template <template <typename, typename> class Container, template <typename> class Allocator>
typename PMergeMe<Container, Allocator>::PairContainer  PMergeMe<Container, Allocator>::merge(
  const PairContainer& pairs)
{
  return merge(pairs, Range(0, pairs.size()));
}

template <template <typename, typename> class Container, template <typename> class Allocator>
typename PMergeMe<Container, Allocator>::PairContainer  PMergeMe<Container, Allocator>::merge(
  const PairContainer& pairs, Range range)
{
  if (range.length < 1)
    return PairContainer();
  switch (range.length)
  {
    case 1:
      return merge_1(pairs, range);
    case 2:
      return merge_2(pairs, range);
    default:
      return merge_n(pairs, range);
  }
}

template <template <typename, typename> class Container, template <typename> class Allocator>
typename PMergeMe<Container, Allocator>::PairContainer  PMergeMe<Container, Allocator>::merge_1(
  const PairContainer& pairs, Range range)
{
  PairContainer merged;
  merged.push_back(pairs[range.index]);
  return merged;
}

template <template <typename, typename> class Container, template <typename> class Allocator>
typename PMergeMe<Container, Allocator>::PairContainer  PMergeMe<Container, Allocator>::merge_2(
  const PairContainer& pairs, Range range)
{
  PairContainer merged;
  Pair a = pairs[range.index];
  Pair b = pairs[range.index + 1];
  if (a.first > b.first)
  {
    merged.push_back(b);
    merged.push_back(a);
  }
  else
  {
    merged.push_back(a);
    merged.push_back(b);
  }
  return merged;
}

template <template <typename, typename> class Container, template <typename> class Allocator>
typename PMergeMe<Container, Allocator>::PairContainer  PMergeMe<Container, Allocator>::merge_n(
  const PairContainer& pairs, Range range)
{
  PairContainer merged;
  const int half = range.length / 2;
  PairContainer left = merge(pairs, Range(range.index, half));
  PairContainer right = merge(pairs, Range(range.index + half, half + range.length % 2));

  typename PairContainer::iterator left_it = left.begin();
  typename PairContainer::iterator right_it = right.begin();

  while (left_it != left.end() || right_it != right.end())
  {
    if (left_it == left.end())
    {
      merged.push_back(*right_it);
      right_it++;
    }
    else if (right_it == right.end())
    {
      merged.push_back(*left_it);
      left_it++;
    }
    else if (left_it->first < right_it->first)
    {
      merged.push_back(*left_it);
      left_it++;
    }
    else
    {
      merged.push_back(*right_it);
      right_it++;
    }
  }
  return merged;
}

template <template <typename, typename> class Container, template <typename> class Allocator>
typename PMergeMe<Container, Allocator>::Sorter  PMergeMe<Container, Allocator>::insert(const PairContainer& pairs)
{
  Sorter              sorter;
  {
    typename PairContainer::const_iterator it = pairs.begin();
    if (it == pairs.end())
      return sorter;

    sorter.main.push_back(it->second);
    sorter.main.push_back(it->first);
    it++;
    while (it != pairs.end())
    {
      sorter.main.push_back(it->first);
      sorter.pend.push_back(it->second);
      it++;
    }
  }
  return sorter;
}
