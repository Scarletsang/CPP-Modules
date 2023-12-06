/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:15:20 by htsang            #+#    #+#             */
/*   Updated: 2023/12/06 20:27:59 by htsang           ###   ########.fr       */
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
    std::cout << "pushed " << value << std::endl;
  #endif
}

RPN::MaybeInt RPN::pop()
{
  if (this->stack_.empty())
    return MaybeInt::Error(Nothing());
  int value = this->stack_.top();
  this->stack_.pop();
  #ifdef DEBUG
    std::cout << "poped " << value << std::endl;
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
      result = a + b;
      break;
    case kSub:
      result = a - b;
      break;
    case kMul:
      result = a * b;
      break;
    case kDiv:
      result = a / b;
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
