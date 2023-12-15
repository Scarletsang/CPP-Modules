/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:18:22 by htsang            #+#    #+#             */
/*   Updated: 2023/11/21 16:13:01 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(): name_("default"), grade_(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name)
{
  if (grade < 1)
  {
    grade_ = 1;
    throw Bureaucrat::GradeTooHighException();
  }
  else if (grade > 150)
  {
    grade_ = 150;
    throw Bureaucrat::GradeTooLowException();
  }
  grade_ = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &obj)
  : name_(obj.name_), grade_(obj.grade_) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &obj)
{
  if (this != &obj)
    grade_ = obj.grade_;
  return (*this);
}

void  Bureaucrat::signForm(Form& form)
{
  try
  {
    form.beSigned(*this);
    std::cout << name_ << " signed " << form.getName() << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << name_ << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
  }
}

std::string Bureaucrat::getName() const
{
  return (name_);
}

int Bureaucrat::getGrade() const
{
  return (grade_);
}

void Bureaucrat::incrementGrade()
{
  if (grade_ <= 1)
    throw Bureaucrat::GradeTooHighException();
  grade_--;
}

void Bureaucrat::decrementGrade()
{
  if (grade_ >= 150)
    throw Bureaucrat::GradeTooLowException();
  grade_++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
  return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
  return "Grade is too low";
}

std::ostream&  operator<<(std::ostream& os, Bureaucrat const &obj)
{
  os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
  return (os);
}
