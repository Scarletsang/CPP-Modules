/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/09/23 14:33:54 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include <iostream>
#include <string>

namespace printer
{
  void  InteractivePrompt()
  {}
} // namespace printer

namespace interactive
{
  int Run()
  {
    std::string input;

    printer::InteractivePrompt();
    std::getline(std::cin, input);
    while (std::cin.good())
    {
      printer::InteractivePrompt();
      std::getline(std::cin, input);
    }
    return EXIT_SUCCESS;
  }
} // namespace battle

namespace noninteractive
{
  int Run()
  {
    return EXIT_SUCCESS;
  }
} // namespace noninteractive

int main(int argc, const char** argv)
{
  if (argc == 1)
    return noninteractive::Run();
  else if (argc == 2 && std::string(argv[1]) == "-i")
    return interactive::Run();
  else
  {
    std::cerr << "Usage: " << argv[0] << " [-i]" << std::endl;
    return EXIT_FAILURE;
  }
}
