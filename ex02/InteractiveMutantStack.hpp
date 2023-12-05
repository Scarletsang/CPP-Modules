/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InteractiveMutantStack.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 23:30:17 by htsang            #+#    #+#             */
/*   Updated: 2023/12/05 15:46:33 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>

#include <iostream>
#include <list>
#include <vector>

#include "interactive/Data.hpp"
#include "MutantStack.hpp"

class InteractiveMutantStack : public interactive::Data
{
  public:
    InteractiveMutantStack();
    InteractiveMutantStack(const InteractiveMutantStack& InteractiveMutantStack);
    virtual ~InteractiveMutantStack();
    const InteractiveMutantStack& operator=(const InteractiveMutantStack& InteractiveMutantStack);

    void  push(int element);
    void  pop();
    void  print() const;
    bool  empty() const;

  private:
    MutantStack<int>                    deque_stack_;
    MutantStack<int, std::list<int> >   list_stack_;
    MutantStack<int, std::vector<int> > vector_stack_;
};
