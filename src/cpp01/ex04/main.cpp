/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:10:18 by htsang            #+#    #+#             */
/*   Updated: 2023/07/19 17:16:57 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StreamReplacer.hpp"

#include <cstdlib>
#include <cstring>

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, const char **argv)
{
  if (argc != 4)
  {
    std::cout << "Usage: ./replace <filename> <string to replace> <string to replace with>" << std::endl;
    return EXIT_FAILURE;
  }
  
  // Open infile stream
  std::fstream  in_file(argv[1], std::fstream::in);
  if (!in_file.is_open())
  {
    std::cout << "Error:" << strerror(errno) << std::endl;
    return EXIT_FAILURE;
  }

  // open outfile stream
  std::string out_file_name = argv[1];
  out_file_name += ".replace";
  std::fstream  out_file(out_file_name, std::fstream::out | std::fstream::trunc);
  if (!in_file.is_open())
  {
    std::cout << "Error: could not open output file" << std::endl;
    return EXIT_FAILURE;
  }

  {
    my::StreamReplacer stream_replacer(in_file, out_file);

    while (!in_file.eof())
    {
      stream_replacer.line(argv[2], argv[3]);
    }
  }
  return EXIT_SUCCESS;
}
