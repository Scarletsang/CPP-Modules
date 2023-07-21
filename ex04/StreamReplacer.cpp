/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StreamReplacer.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:45:03 by htsang            #+#    #+#             */
/*   Updated: 2023/07/21 22:38:03 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StreamReplacer.hpp"

#include <iostream>
#include <string>

namespace my
{
  const int  StreamReplacer::kReadSize = 50;

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
    if (input_.eof())
      output_ << line;
    else
      output_ << line << std::endl;
  }

  void  StreamReplacer::file(const std::string& of, const std::string& to)
  {
    if (of.empty())
      return ;

    std::string buffer;
    char        read_buffer[kReadSize];
    size_t      buffer_size;
    size_t      pos;

    do
    {
      input_.read(read_buffer, kReadSize);
      buffer.append(read_buffer, input_.gcount());
      buffer_size = buffer.size();
      pos = 0;
      while ((pos = buffer.find(of, pos)) != std::string::npos)
      {
        buffer.erase(pos, of.length());
        buffer.insert(pos, to);
        pos += to.length();
      }
      if (pos != 0)
      {
        output_ << buffer.substr(0, pos + of.length() - 1);
        buffer.erase(0, pos + of.length() - 1);
      }
      else if (buffer_size > to.size())
      {
        output_ << buffer.substr(0, buffer_size - to.size());
        buffer.erase(0, buffer_size - to.size());
      }
    }
    while (input_.good());
    output_ << buffer;
  }

  const StreamReplacer& StreamReplacer::operator=(const StreamReplacer& stream_replacer)
  {
    (void) stream_replacer;
    return *this;
  }

} // namespace my
