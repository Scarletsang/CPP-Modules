/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 23:47:18 by htsang            #+#    #+#             */
/*   Updated: 2023/09/24 01:51:37 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#include <string>

#include "Bureaucrat.hpp"

AForm::AForm()
  : name_("default"),
    signed_(false),
    gradeSign_(150),
    gradeExecute_(150),
    target_("") {}

AForm::AForm(std::string name, int gradeSign, int gradeExecute)
  : name_(name),
    signed_(false),
    gradeSign_(gradeSign),
    gradeExecute_(gradeExecute),
    target_("")
{
  if (gradeSign_ < 1 || gradeExecute_ < 1)
    throw AForm::GradeTooHighException();
  else if (gradeSign_ > 150 || gradeExecute_ > 150)
    throw AForm::GradeTooLowException();
}

AForm::AForm(std::string name, int gradeSign, int gradeExecute, std::string target)
  : name_(name),
    signed_(false),
    gradeSign_(gradeSign),
    gradeExecute_(gradeExecute),
    target_(target)
{
  if (gradeSign_ < 1 || gradeExecute_ < 1)
    throw AForm::GradeTooHighException();
  else if (gradeSign_ > 150 || gradeExecute_ > 150)
    throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& form)
  : name_(form.name_),
    signed_(form.signed_),
    gradeSign_(form.gradeSign_),
    gradeExecute_(form.gradeExecute_),
    target_(form.target_) {}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& form)
{
  if (this == &form)
    return (*this);
  this->signed_ = form.signed_;
  return (*this);
}

void  AForm::beSigned(Bureaucrat& bureaucrat)
{
  if (bureaucrat.getGrade() > this->gradeSign_)
    throw AForm::GradeTooLowException();
  this->signed_ = true;
}

std::string const AForm::getName() const
{
  return (this->name_);
}

bool  AForm::isSigned() const
{
  return (this->signed_);
}

int   AForm::getGradeSign() const
{
  return (this->gradeSign_);
}

int   AForm::getGradeExecute() const
{
  return (this->gradeExecute_);
}

std::string AForm::getTarget() const
{
  return (this->target_);
}

const char* AForm::GradeTooHighException::what() const throw()
{
  return ("Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
  return ("Grade too low");
}

const char* AForm::NotSignedException::what() const throw()
{
  return ("Form not signed");
}

void  AForm::checkExecutable(Bureaucrat const & executor) const
{
  if (!this->isSigned())
    throw AForm::NotSignedException();
  else if (executor.getGrade() > this->gradeExecute_)
    throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
  os << "Form " << form.getName() << "(";
  if (form.isSigned())
    os << "signed";
  else
    os << "not signed";
  os << "/sign " << form.getGradeSign() << "/execute " << form.getGradeExecute() << ")";
  return (os);
}
