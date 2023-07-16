/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 21:35:27 by htsang            #+#    #+#             */
/*   Updated: 2023/07/16 23:07:30 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact()
{
	firstName = "";
	lastName = "";
	nickname = "";
	phoneNumber = "";
	darkestSecret = "";
}

Contact::~Contact() {}

Contact::Contact(const Contact &contact)
{
	*this = contact;
}

Contact&	Contact::operator=(const Contact &contact)
{
	firstName = contact.firstName;
	lastName = contact.lastName;
	nickname = contact.nickname;
	phoneNumber = contact.phoneNumber;
	darkestSecret = contact.darkestSecret;
	return (*this);
}

bool	Contact::isComplete()
{
	if (firstName.empty() || \
		lastName.empty() || \
		nickname.empty() || \
		phoneNumber.empty() || \
		darkestSecret.empty())
		return (false);
	return (true);
}

void	Contact::printField(std::string field)
{
	if (field.length() > 10)
	{
		
	}
	std::cout << std::setw(20) << field << ": ";
}

void	Contact::printAbbreviated()
{
	firstName.length();
	std::cout << std::setw(10) << firstName << "|";
	std::cout << std::setw(10) << lastName << "|";
	std::cout << std::setw(10) << nickname << std::endl;
}

