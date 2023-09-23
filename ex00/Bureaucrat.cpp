/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:18:22 by htsang            #+#    #+#             */
/*   Updated: 2023/09/24 00:42:03 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name_("default"), grade_(150) {};

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

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
  return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
  return "Grade is too low";
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

std::ostream&  operator<<(std::ostream& os, Bureaucrat const &obj)
{
  os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
  return (os);
}
