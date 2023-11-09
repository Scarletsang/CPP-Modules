/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:01:50 by htsang            #+#    #+#             */
/*   Updated: 2023/11/09 23:03:08 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template <typename T>
class MutantStack : std::stack<T>
{
  public:
    MutantStack();
    MutantStack(const MutantStack& copy);
    ~MutantStack();

    MutantStack& operator=(const MutantStack& copy);

    
};
