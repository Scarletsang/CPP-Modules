/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 01:52:42 by htsang            #+#    #+#             */
/*   Updated: 2023/09/24 01:56:30 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <iostream>

#include "../Bureaucrat.hpp"
#include "../AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
  : AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
  : AForm("RobotomyRequestForm", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
  : AForm(copy) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
  if (this != &copy)
    AForm::operator=(copy);
  return (*this);
}

void  RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
  checkExecutable(executor);
  std::cout << "* drilling noises *" << std::endl;
  if (rand() % 2)
    std::cout << getTarget() << " has been robotomized successfully" << std::endl;
  else
    std::cout << getTarget() << " robotomization failed" << std::endl;
}
