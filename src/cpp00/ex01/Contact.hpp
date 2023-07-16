/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:38:08 by htsang            #+#    #+#             */
/*   Updated: 2023/07/14 21:52:45 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class	Contact
{
	public:
		Contact();
		~Contact();
		Contact(const Contact &contact);
		Contact&	operator=(const Contact &contact);

		bool	isComplete();
		void	printAbbreviated();
		void	print();

		void	setFirstName(std::string firstName);
		void	setLastName(std::string lastName);
		void	setNickname(std::string nickname);
		void	setPhoneNumber(std::string phoneNumber);
		void	setDarkestSecret(std::string darkestSecret);

	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;

		void	printField(std::string field);
};

#endif