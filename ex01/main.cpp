/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/12/06 16:16:05 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include <iostream>
#include <string>
#include <sstream>

#include "RPN.hpp"
#include "Error.hpp"
#include "Result.hpp"

typedef Result<RPN::Operation, Error> OperationResult;
typedef Result<int, Error>            IntResult;
typedef Result<Nothing, Error>        NoResult;

IntResult  ParseNumber(std::stringstream& ss)
{
  int number;
  ss >> number;
  if (ss.fail())
  {
    ss.clear();
    return IntResult::Error(Error(Error::kInvalidNumber));
  }
  return IntResult::Ok(number);
}

NoResult  PushNumber(int number, RPN& rpn)
{
  rpn.push(number);
  return NoResult::Ok(Nothing());
}

OperationResult ParseOperator(std::stringstream& ss)
{
  char op = ss.peek();

  switch (op)
  {
    case '+':
      ss.get();
      return OperationResult::Ok(RPN::kAdd);
    case '-':
      ss.get();
      return OperationResult::Ok(RPN::kSub);
    case '*':
      ss.get();
      return OperationResult::Ok(RPN::kMul);
    case '/':
      ss.get();
      return OperationResult::Ok(RPN::kDiv);
    default:
      return OperationResult::Error(Error(Error::kInvalidOperand));
  }
}

NoResult  ApplyOperation(RPN::Operation operation, RPN& rpn)
{
  if (rpn.apply(operation))
    return NoResult::Error(Error(Error::kInvalidOperation));
  return NoResult::Ok(Nothing());
}

NoResult ParseExpression(std::stringstream& ss, RPN& rpn)
{
  while (ss.good())
  {
    NoResult result = ParseNumber(ss).chain(PushNumber, rpn);
    if (result.is_ok())
      continue;
    result = ParseOperator(ss).chain(ApplyOperation, rpn);
    if (!result.is_ok())
      return NoResult::Error(result.error());
  }
  return NoResult::Ok(Nothing());
}

int main(int argc, const char** argv)
{
  if (argc == 1)
  {
    std::cout << "usage: " << argv[0] << " [expression]" << std::endl;
    return EXIT_FAILURE;
  }
  RPN               rpn;
  std::stringstream ss;
  for (int i = 0; i < argc; i++)
  {
    ss << argv[i];
    NoResult parse_result = ParseExpression(ss, rpn);
    if (!parse_result.is_ok())
    {
      std::cout << parse_result.error() << std::endl;
      return EXIT_FAILURE;
    }
  }
  switch (rpn.size())
  {
    case 1:
      std::cout << rpn.top().value() << std::endl;
      return EXIT_SUCCESS;
    case 0:
      std::cout << Error(Error::kStackEmpty) << std::endl;
      break;
    default:
      std::cout << Error(Error::kAmbiguous) << std::endl;
      break;
  }
  return EXIT_FAILURE;
}
