/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 01:57:32 by htsang            #+#    #+#             */
/*   Updated: 2023/12/11 22:30:20 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <utility>
#include <memory>
#include <limits>

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
    typedef std::pair<int, int>                             Pair;
    typedef Container<Pair, Allocator<Pair> >               PairContainer;
    typedef Container<int, Allocator<int> >                 IntContainer;
    typedef Container<Maybe<int>, Allocator<Maybe<int> > >  MaybeIntContainer;

    struct Sorter
    {
      IntContainer      main;
      MaybeIntContainer pend;
    };

    static IntContainer   create_ints(int argc, const char** argv);

    static std::pair<PairContainer, Maybe<int> >  create_pairs(const IntContainer& ints);

    static PairContainer  merge(const PairContainer& pairs);
    static PairContainer  merge(const PairContainer& pairs, Range range);
    static PairContainer  merge_1(const PairContainer& pairs, Range range);
    static PairContainer  merge_2(const PairContainer& pairs, Range range);
    static PairContainer  merge_n(const PairContainer& pairs, Range range);

    static Sorter         create_sorter(const PairContainer& pairs);

    static IntContainer   insert(Sorter sorter);
    static void           insert(IntContainer& pairs, int value, int search_till);

    private:
      PMergeMe();
      PMergeMe(const PMergeMe&);
      ~PMergeMe();
      PMergeMe& operator=(const PMergeMe&);
};

/////////////////////////////////////////////////////
////////////   template implementation   ////////////
/////////////////////////////////////////////////////

template <template <typename, typename> class Container, template <typename> class Allocator>
typename PMergeMe<Container, Allocator>::IntContainer  PMergeMe<Container, Allocator>::create_ints(
  int argc, const char** argv)
{
  IntContainer  ints;
  long          value;
  for (int i = 1; i < argc; i++)
  {
    value = std::strtoll(argv[i], NULL, 10);
    if (errno == ERANGE ||
        value < 0 ||
        value < std::numeric_limits<int>::min() ||
        value > std::numeric_limits<int>::max())
      return IntContainer();
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
typename PMergeMe<Container, Allocator>::Sorter PMergeMe<Container, Allocator>::create_sorter(
  const PairContainer& pairs)
{
  Sorter  sorter;
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

template <template <typename, typename> class Container, template <typename> class Allocator>
typename PMergeMe<Container, Allocator>::IntContainer  PMergeMe<Container, Allocator>::insert(Sorter sorter)
{
  InsertionPositions  positions;
  {
    int value;
    int added = 0;

    for (Maybe<int> pend_pos = positions.next();
        pend_pos.is_ok() && static_cast<size_t>(pend_pos.value()) < sorter.pend.size();
        pend_pos = positions.next())
    {
      Maybe<int>& pend_value = sorter.pend[pend_pos.value() - 1];
      value = pend_value.value();
      pend_value = Nothing();
      insert(sorter.main, value, pend_pos.value() + added - 1);
      added++;
    }
  }
  for (typename MaybeIntContainer::const_iterator it = sorter.pend.begin();
      it != sorter.pend.end(); ++it)
  {
    if (it->is_ok())
      insert(sorter.main, it->value(), sorter.main.size());
  }
  return sorter.main;
}

template <template <typename, typename> class Container, template <typename> class Allocator>
void PMergeMe<Container, Allocator>::insert(IntContainer& ints, int value, int length)
{
  int  min = 0;
  int  mid;

  while (min < length)
  {
    mid = (min + length) / 2;
    if (ints[mid] < value)
      min = mid + 1;
    else
      length = mid;
  }
  ints.insert(ints.begin() + min, value);
}
