/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/12/14 20:54:43 by htsang           ###   ########.fr       */
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
#include "Result.hpp"
#include "misc.hpp"

enum  Error
{
  kEmptyArray,
  kUnSortedArray
};

typedef Result<clock_t, Error>  SortResult;

double  Duration(clock_t start, clock_t end)
{
  return static_cast<double>(end - start) * 1000000 / CLOCKS_PER_SEC;
}

void  PrintSumary(const std::string& container_name, size_t size, double duration)
{
  std::cout << "Time to process a range of "
            << size << " elements with " << container_name << ": "
            << duration << " us" << std::endl;
}

template <template <typename, typename> class Container>
SortResult sort(int argc, const char** argv)
{
  typedef PMergeMe<Container>               Algorithm;
  typedef typename Algorithm::PairContainer PairContainer;
  typedef typename Algorithm::IntContainer  IntContainer;

  IntContainer unsorted = Algorithm::create_ints(argc, argv);
  if (unsorted.empty())
    return SortResult::Error(kEmptyArray);
  Print("before", unsorted);
  std::pair<PairContainer, Maybe<int> > pairs = Algorithm::create_pairs(unsorted);
  IntContainer sorted = Algorithm::insert(
                        Algorithm::create_sorter(
                        Algorithm::merge(pairs.first)));
  if (pairs.second.is_ok())
    Algorithm::insert(sorted, pairs.second.value(), sorted.empty() ? 0 : sorted.size() - 1);
  clock_t time = clock();
  Print("after ", sorted);
  if (!Algorithm::is_sorted(sorted))
    return SortResult::Error(kUnSortedArray);
  return SortResult::Ok(time);
}

template <template <typename, typename> class Container>
int logic(int argc, const char** argv, const std::string& container_name)
{
  clock_t     start = clock();
  SortResult  result = sort<Container>(argc, argv);
  if (!result.is_ok())
  {
    switch (result.error())
    {
    case kEmptyArray:
      std::cerr << "Error: empty array" << std::endl;
      break;
    case kUnSortedArray:
      std::cerr << "Error: unsorted array" << std::endl;
      break;
    default:
      std::cerr << "Error: unknown error" << std::endl;
      break;
    }
    return EXIT_FAILURE;
  }
  else
  {
    PrintSumary(container_name, argc - 1, Duration(start, result.value()));
    return EXIT_SUCCESS;
  }
}

int main(int argc, const char** argv)
{
  if (argc == 1)
  {
    std::cerr << "Usage: " << argv[0] << " <number sequences>" << std::endl;
    return EXIT_FAILURE;
  }
  return logic<std::vector>(argc, argv, "std::vector") ||
         logic<std::deque>(argc, argv, "std::deque");
}
