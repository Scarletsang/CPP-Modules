/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/12/06 22:56:11 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "RPN.hpp"
#include "Error.hpp"
#include "Result.hpp"

typedef Result<RPN::Operation, Error> OperationResult;
typedef Result<int, Error>            IntResult;
typedef Result<Nothing, Error>        NoResult;

void  debug(std::stringstream& ss)
{
  int index = ss.tellg();
  std::ios_base::iostate state = ss.rdstate();
  std::bitset<3> bits(state);
  std::cout << "----------------" << std::endl;
  std::cout << "input(" << bits << "): '" << ss.str() << "'" << std::endl;
  std::cout << std::setw(index + 13) << "^" << std::endl;
  std::cout << "----------------" << std::endl;
}

IntResult  ParseNumber(std::stringstream& ss)
{
  std::streampos  pos = ss.tellg();
  int number;
  if (ss >> number)
    return IntResult::Ok(number);
  else
  {
    ss.clear();
    ss.seekg(pos);
    return IntResult::Error(Error(Error::kInvalidNumber));
  }
}

NoResult  PushNumber(int number, RPN& rpn)
{
  rpn.push(number);
  return NoResult::Ok(Nothing());
}

OperationResult ParseOperator(std::stringstream& ss)
{
  std::streampos  pos = ss.tellg();
  char op;

  if (ss >> op)
  {
    switch (op)
    {
      case '+':
        return OperationResult::Ok(RPN::kAdd);
      case '-':
        return OperationResult::Ok(RPN::kSub);
      case '*':
        return OperationResult::Ok(RPN::kMul);
      case '/':
        return OperationResult::Ok(RPN::kDiv);
      default:
        break;
    }
  }
  ss.clear();
  ss.seekg(pos);
  return OperationResult::Error(Error(Error::kInvalidOperand));
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
    #ifdef DEBUG
    debug(ss);
    #endif
    NoResult result = ParseNumber(ss).chain(PushNumber, rpn);
    if (!result.is_ok())
    {
      result = ParseOperator(ss).chain(ApplyOperation, rpn);
      if (!result.is_ok())
        return NoResult::Error(result.error());
    }
    ss >> std::ws;
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
  for (int i = 1; i < argc; ++i)
  {
    ss << " " << argv[i];
    NoResult parse_result = ParseExpression(ss, rpn);
    if (!parse_result.is_ok())
    {
      std::cout << parse_result.error() << std::endl;
      return EXIT_FAILURE;
    }
    ss.clear();
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
