/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 23:41:03 by htsang            #+#    #+#             */
/*   Updated: 2023/09/24 01:49:46 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"

class AForm
{
  public:
    AForm();
    AForm(std::string name, int gradeSign, int gradeExecute);
    AForm(std::string name, int gradeSign, int gradeExecute, std::string target);
    AForm(const AForm& copy);
    virtual ~AForm();
  
    AForm& operator=(const AForm& copy);

    void  beSigned(Bureaucrat& bureaucrat);
    virtual void  execute(Bureaucrat const & executor) const = 0;

    std::string const getName() const;
    bool              isSigned() const;
    int               getGradeSign() const;
    int               getGradeExecute() const;
    std::string       getTarget() const;

    class GradeTooHighException : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };

    class NotSignedException : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };
  
  protected:
    void  checkExecutable(Bureaucrat const & executor) const;
  
  private:
    std::string const name_;
    bool              signed_;
    int const         gradeSign_;
    int const         gradeExecute_;
    std::string       target_;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);