/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:27:44 by htsang            #+#    #+#             */
/*   Updated: 2023/07/19 02:50:25 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include <string>
#include <iostream>

int main(void)
{
  // initialization
  std::string str = "HI THIS IS BRAIN";
  std::string *stringPTR = &str;
  std::string &stringREF = str;

  // print address
  std::cout << "str address: " << &str << std::endl;
  std::cout << "stringPTR holding: " << stringPTR << std::endl;
  std::cout << "stringREF holding: " << &stringREF << std::endl;

  // print value
  std::cout << "str: " << str << std::endl;
  std::cout << "stringPTR: " << *stringPTR << std::endl;
  std::cout << "stringREF: " << stringREF << std::endl;
  
  return EXIT_SUCCESS;
}
