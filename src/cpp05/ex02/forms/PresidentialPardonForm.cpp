/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 01:55:20 by htsang            #+#    #+#             */
/*   Updated: 2023/09/24 01:56:34 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#include <iostream>

#include "../Bureaucrat.hpp"
#include "../AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
  : AForm("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
  : AForm("PresidentialPardonForm", 25, 5, target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
  : AForm(copy) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
  if (this != &copy)
    AForm::operator=(copy);
  return (*this);
}

void  PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
  checkExecutable(executor);
  std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
