/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 21:35:27 by htsang            #+#    #+#             */
/*   Updated: 2023/07/17 23:34:43 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#include <iostream>
#include <iomanip>
#include <ostream>
#include <string>

namespace my
{
  Contact::Contact()
  {
    first_name_ = "";
    last_name_ = "";
    nick_name_ = "";
    phone_number_ = "";
    darkest_secret_ = "";
  }

  Contact::~Contact() {}

  Contact::Contact(const Contact &contact)
  {
    *this = contact;
  }

  Contact&	Contact::operator=(const Contact &contact)
  {
    first_name_ = contact.first_name_;
    last_name_ = contact.last_name_;
    nick_name_ = contact.nick_name_;
    phone_number_ = contact.phone_number_;
    darkest_secret_ = contact.darkest_secret_;
    return *this;
  }

  bool	Contact::is_complete() const
  {
    if (first_name_.empty() || \
      last_name_.empty() || \
      nick_name_.empty() || \
      phone_number_.empty() || \
      darkest_secret_.empty())
      return false;
    return true;
  }

  /////////////////////////////////////
  ////////////   setters   ////////////
  /////////////////////////////////////

  void	Contact::set_first_name(std::string firstName)
  {
    first_name_ = firstName;
  }

  void	Contact::set_last_name(std::string lastName)
  {
    last_name_ = lastName;
  }

  void	Contact::set_nick_name(std::string nickname)
  {
    nick_name_ = nickname;
  }

  void	Contact::set_phone_number(PhoneNumber phoneNumber)
  {
    phone_number_ = phoneNumber;
  }

  void	Contact::set_darkest_secret(std::string darkestSecret)
  {
    darkest_secret_ = darkestSecret;
  }

  //////////////////////////////////////
  ////////////   printers   ////////////
  //////////////////////////////////////

  std::ostream&	Contact::print_abbreviated_field(std::string field) const
  {
    if (field.length() > 10)
    {
      std::cout << field.substr(0, 9) << ".";
    }
    else
    {
      std::cout << std::setw(10) << field;
    }
    return (std::cout);
  }

  std::ostream&	Contact::print_abbreviated() const
  {
    print_abbreviated_field(first_name_) << "|";
    print_abbreviated_field(last_name_) << "|";
    print_abbreviated_field(nick_name_) << "|" << std::endl;
    return std::cout;
  }

  std::ostream&	Contact::print() const
  {
    return (std::cout
      << "First name:     " << first_name_ << std::endl \
      << "Last name:      " << last_name_ << std::endl \
      << "Nickname:       " << nick_name_ << std::endl \
      << "Phone number:   " << phone_number_ << std::endl \
      << "Darkest secret: " << darkest_secret_ << std::endl);
  }

} // namespace my
