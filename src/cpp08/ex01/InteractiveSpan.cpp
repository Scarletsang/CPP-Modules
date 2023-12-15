/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InteractiveSpan.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 23:30:22 by htsang            #+#    #+#             */
/*   Updated: 2023/12/04 22:43:08 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InteractiveSpan.hpp"

#include <ctime>
#include <cstdlib>

#include <iterator>
#include <iostream>
#include <utility>
#include <stdexcept>

#include "Span.hpp"
#include "interactive/Prompt.hpp"
#include "interactive/Data.hpp"

InteractiveSpan::InteractiveSpan()
  : interactive::Data(),
    span_(),
    subprompt_(interactive::Prompt::kForm)
{
  subprompt_.setReprompt("Invalid input. Try again: ");
  subprompt_.registerAction("Enter a number",
    interactive::Action<interactive::PrimitiveData<int>, GetNumberAction>);
  generate(span_.capacity() / 10);
}

InteractiveSpan::InteractiveSpan(const InteractiveSpan& InteractiveSpan)
  : interactive::Data(),
    span_(InteractiveSpan.span_),
    subprompt_(InteractiveSpan.subprompt_) {}

InteractiveSpan::~InteractiveSpan() {}

const InteractiveSpan& InteractiveSpan::operator=(const InteractiveSpan& InteractiveSpan)
{
  if (this != &InteractiveSpan)
    span_ = InteractiveSpan.span_;
  return *this;
}

void  InteractiveSpan::generate(int size)
{
  std::srand(std::time(NULL));
  for (int i = 0; i < size; i++)
    span_.addNumber(std::rand() % 100);
}

void  InteractiveSpan::addNumber(int number)
{
  span_.addNumber(number);
}

int  InteractiveSpan::addNumber()
{
  interactive::PrimitiveData<int> int_data;

  if (subprompt_.run(int_data))
    return EXIT_FAILURE;
  try
  {
    span_.addNumber(int_data.data());
  } catch (const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

void  InteractiveSpan::print() const
{
  for (Span::const_iterator it = span_.begin(); it != span_.end(); ++it)
  {
    std::cout << *it;
    if (it != --span_.end())
    {
      std::cout << ", ";
    }
  }
  std::cout << std::endl;
}

void  InteractiveSpan::status() const
{
  std::cout << "shortest span: " << span_.shortestSpan() << std::endl;
  std::cout << "longest span: " << span_.longestSpan() << std::endl;
}

/////////////////////////////////////////////////////////
////////////   interactive shell functions   ////////////
/////////////////////////////////////////////////////////

typedef std::pair<bool, int> ParserResult;

static ParserResult  ParseInt(const std::string& input)
{
  int i = std::atoi(input.c_str());
  if (i == 0 && input != "0")
    return std::make_pair(false, 0);
  return std::make_pair(true, i);
}

int GetNumberAction(const std::string& input, interactive::PrimitiveData<int>& data)
{
  ParserResult  result = ParseInt(input);

  if (result.first)
  {
    data.data() = result.second;
    return EXIT_SUCCESS;
  }
  return EXIT_FAILURE;
}
