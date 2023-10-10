/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:57:59 by htsang            #+#    #+#             */
/*   Updated: 2023/10/10 18:42:22 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include <string>

#include "forms/PresidentialPardonForm.hpp"
#include "forms/RobotomyRequestForm.hpp"
#include "forms/ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& copy)
{
  *this = copy;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& copy)
{
  if (this == &copy)
    return (*this);
  return (*this);
}

AForm*  Intern::makeForm(std::string form_name, std::string target)
{
  for (size_t i = 0; i < 3; i++)
  {
    if (form_name == form_names_[i])
    {
      std::cout << "Intern creates " << form_name << std::endl;
      switch (i)
      {
      case 0:
        return (new PresidentialPardonForm(target));
      case 1:
        return (new RobotomyRequestForm(target));
      case 2:
        return (new ShrubberyCreationForm(target));
      default:
        break;
      }
      break ;
    }
  }
  std::cout << "Intern can't create " << form_name << std::endl;
  return NULL;
}

const std::string Intern::form_names_[3] = {
  "presidential pardon",
  "robotomy request",
  "shrubbery creation"
};
