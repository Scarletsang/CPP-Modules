/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/12/09 19:49:49 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <cerrno>

#include <iostream>
#include <string>
#include <vector>
#include <deque>

#include "PMergeMe.hpp"

template <typename T, typename U>
std::ostream& operator<<(std::ostream &os, const std::pair<T, U> &pair)
{
  os << "(" << pair.first << ", " << pair.second << ")";
  return os;
}

template <typename T>
void  Print(T &me)
{
  for (size_t i = 0; i < me.size(); i++)
    std::cout << me[i] << " ";
  std::cout << std::endl;
}

template <template <typename, typename> class Container>
int logic(int argc, const char** argv)
{
  PMergeMe<Container> me;

  if (me.fill(argc, argv))
  {
    std::cerr << "Error: Out of range input" << std::endl;
    return EXIT_FAILURE;
  }

  typename PMergeMe<Container>::PairContainer pairs = me.create_pairs();
  
  Print(pairs);
  return EXIT_SUCCESS;
}

int main(int argc, const char** argv)
{
  if (argc == 1)
  {
    std::cerr << "Usage: " << argv[0] << " <number sequences>" << std::endl;
    return EXIT_FAILURE;
  }
  return (logic<std::vector>(argc, argv) || logic<std::deque>(argc, argv));

  // merge the biggest number
  // insert
  // print
}
