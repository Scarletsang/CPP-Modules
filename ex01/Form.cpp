/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 23:47:18 by htsang            #+#    #+#             */
/*   Updated: 2023/09/24 00:52:28 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#include <string>

#include "Bureaucrat.hpp"

Form::Form()
  : name_("default"),
    signed_(false),
    gradeSign_(150),
    gradeExecute_(150) {}

Form::Form(std::string name, int gradeSign, int gradeExecute)
  : name_(name),
    signed_(false),
    gradeSign_(gradeSign),
    gradeExecute_(gradeExecute)
{
  if (gradeSign_ < 1 || gradeExecute_ < 1)
    throw Form::GradeTooHighException();
  else if (gradeSign_ > 150 || gradeExecute_ > 150)
    throw Form::GradeTooLowException();
}

Form::Form(const Form& form)
  : name_(form.name_),
    signed_(form.signed_),
    gradeSign_(form.gradeSign_),
    gradeExecute_(form.gradeExecute_) {}

Form::~Form() {}

Form& Form::operator=(const Form& form)
{
  if (this == &form)
    return (*this);
  this->signed_ = form.signed_;
  return (*this);
}

void  Form::beSigned(Bureaucrat& bureaucrat)
{
  if (bureaucrat.getGrade() > this->gradeSign_)
    throw Form::GradeTooLowException();
  this->signed_ = true;
}

std::string const Form::getName() const
{
  return (this->name_);
}

bool  Form::getSigned() const
{
  return (this->signed_);
}

int   Form::getGradeSign() const
{
  return (this->gradeSign_);
}

int   Form::getGradeExecute() const
{
  return (this->gradeExecute_);
}

const char* Form::GradeTooHighException::what() const throw()
{
  return ("Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
  return ("Grade too low");
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
  os << "Form " << form.getName() << "(";
  if (form.getSigned())
    os << "signed";
  else
    os << "not signed";
  os << "/sign " << form.getGradeSign() << "/execute " << form.getGradeExecute() << ")";
  return (os);
}
