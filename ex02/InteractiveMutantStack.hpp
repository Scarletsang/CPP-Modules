/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InteractiveMutantStack.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 23:30:17 by htsang            #+#    #+#             */
/*   Updated: 2023/12/04 23:49:24 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>

#include <iostream>
#include <list>
#include <vector>

#include "interactive/Prompt.hpp"
#include "interactive/Data.hpp"
#include "MutantStack.hpp"

class InteractiveMutantStack : public interactive::Data
{
  public:
    InteractiveMutantStack();
    InteractiveMutantStack(const InteractiveMutantStack& InteractiveMutantStack);
    virtual ~InteractiveMutantStack();
    const InteractiveMutantStack& operator=(const InteractiveMutantStack& InteractiveMutantStack);

    int   Run();

  private:
    MutantStack<int>                    deque_stack_;
    MutantStack<int, std::list<int> >   list_stack_;
    MutantStack<int, std::vector<int> > vector_stack_;
};
