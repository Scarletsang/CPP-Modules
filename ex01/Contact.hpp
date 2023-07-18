/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:38:08 by htsang            #+#    #+#             */
/*   Updated: 2023/07/18 01:38:57 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <istream>
# include <ostream>
# include <string>

namespace my
{
  class PhoneNumber : public std::string {
    public:
      PhoneNumber& operator=(const char* str)
      {
        std::string::operator=(str);
        return *this;
      }
  };
  
  class	Contact
  {
    public:
      Contact();
      ~Contact();
      Contact(const Contact &contact);
      Contact&	    operator=(const Contact &contact);

      bool	        is_complete() const;

      void	        set_first_name(std::string firstName);
      void	        set_last_name(std::string lastName);
      void	        set_nick_name(std::string nickname);
      void	        set_phone_number(PhoneNumber phoneNumber);
      void	        set_darkest_secret(std::string darkestSecret);

      std::ostream& print_abbreviated() const;
      std::ostream& print() const;

    private:
      std::string	  first_name_;
      std::string	  last_name_;
      std::string	  nick_name_;
      PhoneNumber	  phone_number_;
      std::string	  darkest_secret_;

      std::ostream&	print_abbreviated_field(std::string field) const;
  }; // class Contact

} // namespace my


#endif