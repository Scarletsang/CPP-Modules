/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/12/11 23:09:50 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <cerrno>
#include <ctime>

#include <iostream>
#include <string>
#include <utility>
#include <typeinfo>
#include <memory>
#include <vector>
#include <deque>

#include "PMergeMe.hpp"
#include "misc.hpp"

double  Duration(clock_t start)
{
  return static_cast<double>(clock() - start) * 1000000 / CLOCKS_PER_SEC;
}

void  PrintSumary(const std::string& container_name, size_t size, double duration)
{
  std::cout << "Time to process a range of "
            << size << " elements with " << container_name << ": "
            << duration << " us" << std::endl;
}

template <template <typename, typename> class Container>
size_t logic(int argc, const char** argv)
{
  typedef PMergeMe<Container>               Algorithm;
  typedef typename Algorithm::PairContainer PairContainer;
  typedef typename Algorithm::IntContainer  IntContainer;

  IntContainer unsorted = Algorithm::create_ints(argc, argv);
  if (unsorted.empty())
    return 0;
  Print("before", unsorted);
  std::pair<PairContainer, Maybe<int> > pairs = Algorithm::create_pairs(unsorted);
  IntContainer sorted = Algorithm::insert(
                        Algorithm::create_sorter(
                        Algorithm::merge(pairs.first)));
  if (pairs.second.is_ok())
    Algorithm::insert(sorted, pairs.second.value(), sorted.size());
  Print("after ", sorted);
  return unsorted.size();
}

int main(int argc, const char** argv)
{
  if (argc == 1)
  {
    std::cerr << "Usage: " << argv[0] << " <number sequences>" << std::endl;
    return EXIT_FAILURE;
  }
  clock_t start;
  size_t size;

  start = clock();
  size = logic<std::vector>(argc, argv);
  if (size == 0)
  {
    std::cerr << "Error" << std::endl;
    return EXIT_FAILURE;
  }
  PrintSumary("std::vector", size, Duration(start));

  start = clock();
  size = logic<std::deque>(argc, argv);
  if (size == 0)
  {
    std::cerr << "Error" << std::endl;
    return EXIT_FAILURE;
  }
  PrintSumary("std::deque", size, Duration(start));
  return EXIT_SUCCESS;
}
