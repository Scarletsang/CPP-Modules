/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/12/07 23:13:19 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include <iostream>
#include <string>
#include <vector>
#include <deque>

#include "me/Me.hpp"

void  Print(IMe &me)
{
  for (size_t i = 0; i < me.size(); i++)
    std::cout << me[i] << " ";
  std::cout << std::endl;
}

int main(int argc, const char** argv)
{
  if (argc == 1)
  {
    std::cerr << "Usage: " << argv[0] << " <number sequences>" << std::endl;
    return EXIT_FAILURE;
  }
  Me<std::vector<int> > vector_me;
  Me<std::deque<int> >  deque_me;

  IMe &v_me = vector_me;
  IMe &d_me = deque_me;

  v_me.push_back(1);
  v_me.push_back(2);
  d_me.push_back(3);
  d_me.push_back(4);

  Print(v_me);
  Print(d_me);
  // parse
  // merge the biggest number
  // insert
  // print
}
