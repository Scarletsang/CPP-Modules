/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:41:05 by htsang            #+#    #+#             */
/*   Updated: 2023/07/17 23:42:04 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <cstdlib>

#include <iostream>
#include <iomanip>

#include "Contact.hpp"

namespace my
{

  PhoneBook::PhoneBook()
  {
    contact_insert_index_ = 0;
    contact_count_ = 0;
  }

  PhoneBook::~PhoneBook() {}

  PhoneBook::PhoneBook(const PhoneBook &phone_book) { (void) phone_book; }

  PhoneBook& PhoneBook::operator=(const PhoneBook &phone_book)
  {
    (void) phone_book;
    return *this;
  }

  int	PhoneBook::add(const Contact &contact)
  {
    if (!contact.is_complete())
      return EXIT_FAILURE;
    contacts_[contact_insert_index_] = contact;
    contact_insert_index_ = (contact_insert_index_ + 1) % kMaxContactCount;
    if (contact_count_ < kMaxContactCount)
      contact_count_++;
    return EXIT_SUCCESS;
  }
  
  const Contact *PhoneBook::search(int index) const
  {
    if (index >= kMaxContactCount && index < 0)
      std::cerr << "Index out of range" << std::endl;
    else if (index >= contact_count_)
    {
      std::cerr << "Index out of range" << std::endl;
      std::cerr << "Only " << contact_count_ << " contacts available" << std::endl;
    }
    else
      return &contacts_[index];
    return NULL;
  }

  std::ostream&	PhoneBook::print_contacts() const
  {
    std::cout << "|     index|first name| last name|  nickname|" << std::endl;
    for (int i = 0; i < contact_count_; i++)
    {
      std::cout << "|" << std::setw(10) << i << "|";
      contacts_[i].print_abbreviated();
    }
    return std::cout;
  }

} // namespace my