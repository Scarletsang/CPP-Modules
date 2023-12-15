/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:15:20 by htsang            #+#    #+#             */
/*   Updated: 2023/12/06 23:03:12 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
  : stack_() {}

RPN::RPN(RPN const& other)
{
  if (this != &other)
    *this = other;
}

RPN& RPN::operator=(RPN const& other)
{
  if (this != &other)
    this->stack_ = other.stack_;
  return *this;
}

RPN::~RPN() {}

void  RPN::push(int value)
{
  this->stack_.push(value);
  #ifdef DEBUG
    print();
  #endif
}

RPN::MaybeInt RPN::pop()
{
  if (this->stack_.empty())
    return MaybeInt::Error(Nothing());
  int value = this->stack_.top();
  this->stack_.pop();
  #ifdef DEBUG
    print();
  #endif
  return MaybeInt::Ok(value);
}

int RPN::apply(Operation op)
{
  if (this->stack_.size() < 2)
    return EXIT_FAILURE;
  int  a = this->pop().value();
  int  b = this->pop().value();
  int result;

  switch (op)
  {
    case kAdd:
      result = b + a;
      break;
    case kSub:
      result = b - a;
      break;
    case kMul:
      result = b * a;
      break;
    case kDiv:
      if (a == 0)
        return EXIT_FAILURE;
      result = b / a;
      break;
    default:
      return EXIT_FAILURE;
  }
  this->push(result);
  return EXIT_SUCCESS;
}

RPN::MaybeInt RPN::top() const
{
  if (this->stack_.empty())
    return MaybeInt::Error(Nothing());
  return MaybeInt::Ok(this->stack_.top());
}

bool RPN::empty() const
{
  return this->stack_.empty();
}

int RPN::size() const
{
  return this->stack_.size();
}

static void  Print(std::stack<int>& stack)
{
  if (stack.empty())
    return;
  int value = stack.top();
  stack.pop();
  Print(stack);
  std::cout << value << " ";
}

void RPN::print() const {
  std::stack<int> copy = stack_;
  std::cout << "stack: ";
  if (copy.empty()) {
      std::cout << "[ empty ]" << std::endl;
      return;
  }
  std::cout << "[ ";
  Print(copy);
  std::cout << "]" << std::endl;
}
