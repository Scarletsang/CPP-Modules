/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:59:29 by htsang            #+#    #+#             */
/*   Updated: 2023/07/17 22:57:51 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# include <ostream>

namespace my
{

  class PhoneBook
  {
    public:
      static const int  kMaxContactCount = 8;

      PhoneBook();
      ~PhoneBook();
      PhoneBook(const PhoneBook &phone_book);
      PhoneBook&	  operator=(const PhoneBook &phone_book);

      int	          add(const Contact &contact);
      const Contact *search(int index) const;

      std::ostream&	print_contacts() const;

    private:
      Contact	      contacts_[kMaxContactCount];
      int	        	contact_insert_index_;
      int           contact_count_;
  }; // class PhoneBook

} // namespace my

#endif