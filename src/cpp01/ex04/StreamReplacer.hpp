/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StreamReplacer.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:15:47 by htsang            #+#    #+#             */
/*   Updated: 2023/07/19 18:57:35 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STREAMREPLACER_HPP
# define STREAMREPLACER_HPP

# include <iostream>

namespace my
{
  class StreamReplacer
  {
    public:
      const static int  kReadSize;
      StreamReplacer(\
        std::istream &input = std::cin, \
        std::ostream &output = std::cout) \
        : input_(input), output_(output) {};
      ~StreamReplacer() {};
      StreamReplacer(const StreamReplacer& stream_replacer)
        : input_(stream_replacer.input_), output_(stream_replacer.output_) {};

      void  line(const std::string& of, const std::string& to);
      void  file(const std::string& of, const std::string& to);

    private:
      std::istream& input_;
      std::ostream& output_;
  
      const StreamReplacer& operator=(const StreamReplacer& stream_replacer);
  };
} // namespace my

#endif