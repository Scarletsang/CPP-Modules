/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/11/24 20:25:20 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include <iostream>
#include <string>
#include <typeinfo>

#include "InteractivePrompt.hpp"
#include "iter.hpp"
#include "Fixed.hpp"

namespace test
{
  template <typename T>
  void  IterPrinterFunc(T const & i)
  {
    std::cout << i << std::endl;
  }

  template <typename T>
  void  IterResetFunc(T const & i)
  {
    T&  mutable_i = const_cast<T&>(i);
    mutable_i = T();
  }
} // namespace test

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

namespace interactive
{
  struct States
  {
    int   int_range[2];
    Fixed fixed_range[2];
  };

  template <int index>
  int FillNumber(std::string input, struct States& states)
  {
    try
    {
      states.int_range[index] = parser::Int(input);
      states.fixed_range[index] = parser::FixedNumber(input);
    }
    catch(const std::exception& e)
    {
      return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
  }

  template <typename T>
  T*  CreateArray(T range[2], size_t* size)
  {
    size_t  array_size;
    if (range[0] < range[1])
      array_size = static_cast<size_t>(range[1]) - static_cast<size_t>(range[0]) + 1;
    else
      array_size = static_cast<size_t>(range[0]) - static_cast<size_t>(range[1]) + 1;
    *size = array_size;
    T* array = new T[array_size];
    if (range[0] < range[1])
      for (size_t i = 0; i < array_size; i++)
        array[i] = range[0] + T(static_cast<int>(i));
    else
      for (size_t i = 0; i < array_size; i++)
        array[i] = range[0] - T(static_cast<int>(i));
    return array;
  }

  int Iterate(struct States& states)
  {
    size_t  size;
    std::cout << std::endl;
    {
      int*    int_array = CreateArray(states.int_range, &size);
      std::cout << "Created an int array of size " << size << std::endl;
      std::cout << "Action 1: printing" << std::endl;
      iter(int_array, size, test::IterPrinterFunc);
      std::cout << "Action 2: reseting values" << std::endl;
      iter(int_array, size, test::IterResetFunc);
      std::cout << "Action 3: printing" << std::endl;
      iter(int_array, size, test::IterPrinterFunc);
      delete[] int_array;
    }
    std::cout << std::endl;
    {
      Fixed*  fixed_array = CreateArray(states.fixed_range, &size);
      std::cout << "Created a Fixed array of size " << size << std::endl;
      std::cout << "Action 1: printing" << std::endl;
      iter(fixed_array, size, test::IterPrinterFunc);
      std::cout << "Action 2: reseting values" << std::endl;
      iter(fixed_array, size, test::IterResetFunc);
      std::cout << "Action 3: printing" << std::endl;
      iter(fixed_array, size, test::IterPrinterFunc);
      delete[] fixed_array;
    }
    return EXIT_SUCCESS;
  }

  int Run()
  {
    struct States                     states;
    InteractivePrompt<struct States>  prompt(InteractivePrompt<struct States>::kForm);

    prompt.setPrompt("Please enter a range specified by two numbers");
    prompt.setReprompt("Invalid input. Try again: ");
    prompt.registerAction("Enter the first number", FillNumber<0>);
    prompt.registerAction("Enter the second number", FillNumber<1>);
    if (prompt.run(states) == EXIT_SUCCESS)
      return Iterate(states);
    else
      return EXIT_FAILURE;
  }
} // namespace battle

namespace noninteractive
{
  int Run()
  {
    struct interactive::States states;

    states.int_range[0] = -5;
    states.int_range[1] = 5;
    states.fixed_range[0] = Fixed(-5.0f);
    states.fixed_range[1] = Fixed(5.0f);

    interactive::Iterate(states);
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
