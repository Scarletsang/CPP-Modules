/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/10/29 18:33:46 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include <iostream>
#include <iomanip>
#include <string>

#include "Data.hpp"
#include "Serializer.hpp"

namespace printer
{
  void  OriginaldData(Data* data)
  {
    std::cout << "Original    : " << *data << " [" << data << "]" << std::endl;
  }

  void  AfterSerializedData(uintptr_t data)
  {
    std::cout << "serialized  : " << std::showbase << std::hex << data << std::endl;
    std::cout << std::resetiosflags(std::ios::showbase | std::ios::hex);
  }

  void  AfterDeserializedData(Data* data)
  {
    std::cout << "deserialized: " << *data << " [" << data << "]" << std::endl;
  }

  void  AddressComparation(bool is_same)
  {
    std::cout << "Received data has "
              << (is_same ? "the same " : "a different")
              << "address as the original data" << std::endl;
  }
}

namespace test
{
  int SerializeThenDeserialize(int a, int b)
  {
    Data  data(a, b);
    printer::OriginaldData(&data);

    uintptr_t serialized = Serializer::serialize(&data);
    printer::AfterSerializedData(serialized);

    Data* deserialized = Serializer::deserialize(serialized);
    printer::AfterDeserializedData(deserialized);
    if (deserialized == &data)
    {
      printer::AddressComparation(true);
      return EXIT_SUCCESS;
    }
    else
    {
      printer::AddressComparation(false);
      return EXIT_FAILURE;
    }
  }
} // namespace test

int main(int argc, const char* argv[])
{
  if (argc == 3)
  {
    return test::SerializeThenDeserialize(atoi(argv[1]), atoi(argv[2]));
  }
  else
  {
    std::cerr << "Usage: " << argv[0] << " <int> <int>" << std::endl;
    return EXIT_FAILURE;
  }
}
