/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/12/06 00:38:13 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include <iostream>
#include <string>
#include <sstream>

#include "RPN.hpp"
#include "Error.hpp"

Error ParseExpression(std::stringstream& ss, RPN& rpn)
{
  int number;

  while (ss.good())
  {
    // TODO
  }
}

int main(int argc, const char** argv)
{
  if (argc == 1)
  {
    std::cout << "usage: " << argv[0] << " [expression]" << std::endl;
    return EXIT_FAILURE;
  }
  RPN               rpn;
  std::stringstream ss;
  Error             err;
  for (int i = 0; i < argc; i++)
  {
    ss << argv[i];
    err = ParseExpression(ss, rpn);
    if (err.code() != Error::kOk)
    {
      std::cout << err << std::endl;
      return EXIT_FAILURE;
    }
  }
  switch (rpn.size())
  {
    case 1:
      std::cout << rpn.top() << std::endl;
      return EXIT_SUCCESS;
    case 0:
      std::cout << Error(Error::kStackEmpty) << std::endl;
      break;
    default:
      std::cout << Error(Error::kAmbiguous) << std::endl;
      break;
  }
  return EXIT_FAILURE;
}
