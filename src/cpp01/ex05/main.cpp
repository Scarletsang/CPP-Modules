/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:26:43 by htsang            #+#    #+#             */
/*   Updated: 2023/07/21 19:55:55 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <cstdlib>

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
  karin::Harl harl;

  if (argc != 2)
  {
    std::cout << "Usage: ./harl [debug|info|warning|error]" << std::endl;
    return EXIT_FAILURE;
  }
  harl.complain(argv[1]);
  return EXIT_SUCCESS;
}
