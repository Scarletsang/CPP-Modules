/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/11/02 22:53:02 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <cstdarg>

#include <iostream>
#include <string>
#include <typeinfo>
#include <exception>

#include "InteractivePrompt.hpp"
#include "whatever.hpp"
#include "Fixed.hpp"

namespace parser
{
  template <typename T, typename U>
  bool  IsInRange(T value)
  {
    if (typeid(U) == typeid(float) || typeid(U) == typeid(double))
      return (value >= -std::numeric_limits<U>::max() && value <= std::numeric_limits<U>::max());
    else
      return (value >= std::numeric_limits<U>::min() && value <= std::numeric_limits<U>::max());
  }

  int Int(std::string& input)
  {
    int i = std::atoi(input.c_str());
    if (i == 0 && input != "0")
      throw std::invalid_argument("Invalid input");
    return i;
  }

  Fixed FixedNumber(std::string& input)
  {
    return Fixed(static_cast<float>(std::strtod(input.c_str(), NULL)));
  }
} // namespace parser

namespace printer
{
  template <typename T>
  void  Value(T& value)
  {
    std::cout << value << "[" << &value << "]";
  }

  template <typename T, typename U>
  void  TwoArgumentFunction(std::string name, T& argument1, U& argument2)
  {
    std::cout << name << "(";
    Value(argument1);
    std::cout << ", ";
    Value(argument2);
    std::cout << ")";
  }
} // namespace printer

namespace interactive
{
  template <int index>
  int FillNumber(std::string input, struct States& states);

  struct States
  {
    int                               ints[2];
    Fixed                             fixeds[2];
    InteractivePrompt<struct States>  form_prompt;


    States() : form_prompt(InteractivePrompt<struct States>::kForm)
    {
      form_prompt.setReprompt("Invalid input. Try again: ");
      form_prompt.registerAction("Enter the first number", FillNumber<0>);
      form_prompt.registerAction("Enter the second number", FillNumber<1>);
    }
  };

  template <int index>
  int FillNumber(std::string input, struct States& states)
  {
    try
    {
      states.ints[index] = parser::Int(input);
      states.fixeds[index] = parser::FixedNumber(input);
    }
    catch(const std::exception& e)
    {
      return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
  }

  int MinAction(std::string input, struct States& states)
  {
    (void) input;
    if (states.form_prompt.run(states))
      return EXIT_FAILURE;
    printer::TwoArgumentFunction("int:   min", states.ints[0], states.ints[1]);
    std::cout << " = " << ::min(states.ints[0], states.ints[1]) << std::endl;
    printer::TwoArgumentFunction("Fixed: min", states.fixeds[0], states.fixeds[1]);
    std::cout << " = " << ::min(states.fixeds[0], states.fixeds[1]) << std::endl;
    return EXIT_SUCCESS;
  }

  int MaxAction(std::string input, struct States& states)
  {
    (void) input;
    if (states.form_prompt.run(states))
      return EXIT_FAILURE;
    printer::TwoArgumentFunction("int:   max", states.ints[0], states.ints[1]);
    std::cout << " = " << ::max(states.ints[0], states.ints[1]) << std::endl;
    printer::TwoArgumentFunction("Fixed: max", states.fixeds[0], states.fixeds[1]);
    std::cout << " = " << ::max(states.fixeds[0], states.fixeds[1]) << std::endl;
    return EXIT_SUCCESS;
  }

  int SwapAction(std::string input, struct States& states)
  {
    (void)input;
    if (states.form_prompt.run(states))
      return EXIT_FAILURE;
    std::cout << "int: ";
    printer::Value(states.ints[0]);
    std::cout << " ";
    printer::Value(states.ints[1]);
    std::cout << std::endl;
    ::swap(states.ints[0], states.ints[1]);
    std::cout << "after swap: ";
    printer::Value(states.ints[0]);
    std::cout << " ";
    printer::Value(states.ints[1]);
    std::cout << std::endl;

    std::cout << "Fixed: ";
    printer::Value(states.fixeds[0]);
    std::cout << " ";
    printer::Value(states.fixeds[1]);
    std::cout << std::endl;
    ::swap(states.fixeds[0], states.fixeds[1]);
    std::cout << "after swap: ";
    printer::Value(states.fixeds[0]);
    std::cout << " ";
    printer::Value(states.fixeds[1]);
    std::cout << std::endl;

    (void)states;
    return EXIT_SUCCESS;
  }

  int Exit(std::string input, struct States& states)
  {
    (void)input;
    (void)states;
    return EXIT_FAILURE;
  }

  int Run()
  {
    struct States                     states;
    InteractivePrompt<struct States>  prompt;

    prompt.setPrompt("Enter a number");
    prompt.setReprompt("Invalid input. Try again: ");
    prompt.registerAction("min", MinAction);
    prompt.registerAction("max", MaxAction);
    prompt.registerAction("swap", SwapAction);
    prompt.registerAction("exit", Exit);
    prompt.shell(states);
    return EXIT_SUCCESS;
  }
} // namespace interactive

namespace noninteractive
{
  int Run()
  {
    int a = 2;
    int b = 3;

    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return EXIT_SUCCESS;
  }
} // namespace noninteractive

int main(int argc, const char** argv)
{
  if (argc == 1)
    return noninteractive::Run();
  else if (argc == 2 && std::string(argv[1]) == "-i")
    return interactive::Run();
  else
  {
    std::cerr << "Usage: " << argv[0] << " [-i]" << std::endl;
    return EXIT_FAILURE;
  }
}
