/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:29:52 by htsang            #+#    #+#             */
/*   Updated: 2023/12/09 20:23:28 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>

#include <memory>
#include <utility>
#include <iostream>

#include "me/Me.hpp"
#include "me/IMe.hpp"
#include "Box.hpp"
#include "Maybe.hpp"

class PMergeMe
{
  public:
    typedef Box<IMe<int> > IntContainer;
    typedef Box<IMe<std::pair<int, int> > > PairContainer;

    struct Sorter
    {
      Box<PairContainer>  pairs;
      Maybe<int>          leftover;
    };

    PMergeMe();
    PMergeMe(const PMergeMe &copy);
    ~PMergeMe();
    PMergeMe& operator=(const PMergeMe &copy);

    template <template <typename, typename> class Container>
    Maybe<IntContainer> sort(int argc, const char** argv) const;

    template <template <typename, typename> class Container>
    Maybe<IntContainer> create_ints(int argc, const char** argv) const;

    template <template <typename, typename> class Container>
    Sorter              create_sorter(const IntContainer& ints) const;

    template <template <typename, typename> class Container>
    Sorter&             sort(Sorter& sorter) const;

};

/////////////////////////////////////////////////////
////////////   template implementation   ////////////
/////////////////////////////////////////////////////

template <template <typename, typename> class Container>
PMergeMe<Container>::PMergeMe()
  : me_() {}

template <template <typename, typename> class Container>
PMergeMe<Container>::PMergeMe(const PMergeMe &copy)
  : me_(copy.me_) {}

template <template <typename, typename> class Container>
PMergeMe<Container>::~PMergeMe() {}

template <template <typename, typename> class Container>
PMergeMe<Container>& PMergeMe<Container>::operator=(const PMergeMe &copy)
{
  if (this != &copy)
    me_ = copy.me_;
  return *this;
}

template <template <typename, typename> class Container>
Maybe<typename PMergeMe<Container>::IntContainer>   PMergeMe<Container>::fill(int argc, const char** argv)
{
  IntContainer  me;
  long n;
  for (int i = 1; i < argc; i++)
  {
    n = std::strtol(argv[i], NULL, 10);
    if (errno == ERANGE)
    {
      errno = 0;
      return Nothing();
    }
    else
      me.push_back(n);
  }
  return me;
}

template <template <typename, typename> class Container>
typename PMergeMe<Container>::PairContainer PMergeMe<Container>::create_pairs(const IntContainer& ints) const
{
  PairContainer pairs;
  Maybe<int> number;
  for (size_t i = 0; i < me_.size(); i++)
  {
    if (number.is_ok())
    {
      pairs.push_back(std::make_pair(number.value(), me_[i]));
      number = Nothing();
    }
    else
      number = me_[i];
  }
  return pairs;
}
