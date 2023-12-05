/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:15:20 by htsang            #+#    #+#             */
/*   Updated: 2023/12/05 23:27:44 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

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
}

RPN::MaybeInt RPN::pop()
{
  if (this->stack_.empty())
    return MaybeInt::Error(Nothing());
  int value = this->stack_.top();
  this->stack_.pop();
  return MaybeInt::Ok(value);
}

int RPN::apply(Operation op)
{
  MaybeInt  a = this->pop();
  if (!a.is_ok())
    return EXIT_FAILURE;
  MaybeInt  b = this->pop();
  if (!b.is_ok())
    return EXIT_FAILURE;
  int result;

  switch (op)
  {
    case kAdd:
      result = a.value() + b.value();
      break;
    case kSub:
      result = a.value() - b.value();
      break;
    case kMul:
      result = a.value() * b.value();
      break;
    case kDiv:
      result = a.value() / b.value();
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
