/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:57:22 by htsang            #+#    #+#             */
/*   Updated: 2023/12/06 22:39:12 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

#include "Result.hpp"

struct Nothing
{
  Nothing() {};
};

class RPN
{
  public:
    enum Operation
    {
      kAdd,
      kSub,
      kMul,
      kDiv
    };
    typedef Result<int, Nothing> MaybeInt;

    RPN();
    RPN(RPN const& other);
    RPN& operator=(RPN const& other);
    ~RPN();

    void      push(int value);
    MaybeInt  pop();
    int       apply(Operation op);

    MaybeInt  top() const;
    bool      empty() const;
    int       size() const;

    void      print() const;
  
  private:
    std::stack<int> stack_;
};
