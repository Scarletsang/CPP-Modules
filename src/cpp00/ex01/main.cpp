/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:45:55 by htsang            #+#    #+#             */
/*   Updated: 2023/07/18 17:58:14 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

#include <cstdlib>
#include <cctype>
#include <cstring>

#include <iostream>
#include <iomanip>

#include "Contact.hpp"
#include "PhoneBook.hpp"

namespace my
{
  static bool IsValid(const PhoneNumber &input)
  {
    size_t i;
    size_t digit_count;
  
    if (input[0] == '+')
      i = 1;
    else
      i = 0;
    digit_count = 0;
    while (i < input.size())
    {
      if (std::isdigit(input[i]))
      {
        digit_count++;
      }
      else if (input[i] != ' ')
      {
        std::cerr << "Expects numeric input or spaces. ";
        return (false);
      }
      i++;
    }
    if (digit_count < 7)
    {
      std::cerr << "Phone number must have at least 7 digits. ";
      return (false);
    }
    return (true);
  }

  static bool IsValid(const NumericString &input)
  {
    for (size_t i = 0; i < input.size(); i++)
    {
      if (!std::isdigit(input[i]))
      {
        std::cerr << "Expects numeric input. ";
        return (false);
      }
    }
    return (true);
  }

  static bool IsValid(const std::string &input)
  {
    (void) input;
    return (true);
  }

  template <typename T>
  static int  GetInput(const std::string &prompt, T &input)
  {
    std::cout << prompt;
    std::getline(std::cin, input);
    while (!std::cin.eof())
    {
      if (input.empty())
      {
        std::cerr << "Field cannot be empty. Please input again: ";
      }
      else if (!IsValid(input))
      {
        std::cerr << "Please input again: ";
      }
      else
      {
        return EXIT_SUCCESS;
      }
      std::getline(std::cin, input);
    }
    return EXIT_FAILURE;
  }

  static int  AddContact(PhoneBook &phone_book)
  {
    std::string input;
    Contact     contact;
  
    do
    {
      if (GetInput("Enter first name: ", input))
        return EXIT_FAILURE;
      contact.set_first_name(input);
      if (GetInput("Enter last name: ", input))
        return EXIT_FAILURE;
      contact.set_last_name(input);
      if (GetInput("Enter nickname: ", input))
        return EXIT_FAILURE;
      contact.set_nick_name(input);
      {
        PhoneNumber phone_number;

        if (GetInput("Enter phone number: ", phone_number))
          return EXIT_FAILURE;
        contact.set_phone_number(phone_number);
      }
      if (GetInput("Enter darkest secret: ", input))
        return EXIT_FAILURE;
      contact.set_darkest_secret(input);
    }
    while (phone_book.add(contact));
    return EXIT_SUCCESS;
  }

  static int  SearchContact(const PhoneBook &phone_book)
  {
      my::NumericString index;
      const my::Contact *contact;

      phone_book.print_contacts();
      if (my::GetInput("Enter index: ", index))
        return EXIT_FAILURE;
      if ((contact = phone_book.search(atoi(index.c_str()))) != NULL)
        contact->print();
      return EXIT_SUCCESS;
  }
} // namespace my


int main(void)
{
  my::PhoneBook phone_book;
  std::string   input;

  while (!std::cin.eof())
  {
    std::cout << "Avaliable commands: ADD, SEARCH, EXIT" << std::endl;
    std::getline(std::cin, input);
    if (input.empty())
    {
      std::cerr << "Empty command received" << std::endl;
    }
    else if (strcmp(input.c_str(), "EXIT") == 0)
      return EXIT_SUCCESS;
    else if (strcmp(input.c_str(), "ADD") == 0)
    {
      if (my::AddContact(phone_book))
        return EXIT_FAILURE;
    }
    else if (strcmp(input.c_str(), "SEARCH") == 0)
    {
      if (my::SearchContact(phone_book))
        return EXIT_FAILURE;
    }
    else
    {
      std::cerr << "Invalid command received: '" << input << "'" << std::endl;
    }
  }
  return EXIT_FAILURE;
}
