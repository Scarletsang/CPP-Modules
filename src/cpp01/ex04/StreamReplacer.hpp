/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StreamReplacer.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:15:47 by htsang            #+#    #+#             */
/*   Updated: 2023/07/19 11:23:05 by htsang           ###   ########.fr       */
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
      StreamReplacer(\
        std::istream &input = std::cin, \
        std::ostream &output = std::cout)
        : _input(input), _output(output) {};
      ~StreamReplacer() {};

      void replace();

    private:
      std::istream& _input;
      std::ostream& _output;
  }
} // namespace my

#endif