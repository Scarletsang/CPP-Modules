/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Slice.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:05:26 by htsang            #+#    #+#             */
/*   Updated: 2023/12/09 20:08:45 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
class Slice
{
  public:
    Slice(T& container);
    Slice(T& container, int start, int end);
    Slice(const Slice &copy);
    ~Slice();
    Slice& operator=(const Slice &copy);

  private:
    int   start;
    int   end;
    T&    container;
};
