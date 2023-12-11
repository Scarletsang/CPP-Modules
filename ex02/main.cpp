/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/12/11 03:13:09 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <cerrno>

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <deque>

#include "PMergeMe.hpp"
#include "misc.hpp"

template <template <typename, typename> class Container>
int logic(int argc, const char** argv)
{
  typedef typename PMergeMe<Container>::PairContainer PairContainer;
  typedef typename PMergeMe<Container>::Sorter        Sorter;
  PMergeMe<Container> pmm;

  std::pair<PairContainer, Maybe<int> > pairs = pmm.create_pairs(pmm.create_ints(argc, argv));
  Sorter sorter = pmm.insert(pmm.merge(pairs.first));
  Print(sorter.main);
  Print(sorter.pend);
  return EXIT_SUCCESS;
}

int main(int argc, const char** argv)
{
  if (argc == 1)
  {
    std::cerr << "Usage: " << argv[0] << " <number sequences>" << std::endl;
    return EXIT_FAILURE;
  }
  return logic<std::vector>(argc, argv) && logic<std::deque>(argc, argv);
}
