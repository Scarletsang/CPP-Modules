/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StreamReplacer.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:45:03 by htsang            #+#    #+#             */
/*   Updated: 2023/07/19 19:37:05 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StreamReplacer.hpp"

#include <iostream>
#include <string>

namespace my
{
  const int  kReadSize = 50;

  void  StreamReplacer::line(const std::string& of, const std::string& to)
  {
    std::string line;
    size_t      pos = 0;

    std::getline(input_, line);
    while ((pos = line.find(of, pos)) != std::string::npos)
    {
      line.erase(pos, of.length());
      line.insert(pos, to);
      pos += to.length();
    }
    output_ << line << std::endl;
  }

  void  StreamReplacer::file(const std::string& of, const std::string& to)
  {
    std::string buffer;
    char        read_buffer[kReadSize];

    do
    {
      input_.read(read_buffer, kReadSize);
      buffer.append(read_buffer, input_.gcount());
    }
    while (input_.good());
  }

  const StreamReplacer& StreamReplacer::operator=(const StreamReplacer& stream_replacer)
  {
    (void) stream_replacer;
    return *this;
  }

} // namespace my
