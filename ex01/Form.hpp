/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 23:41:03 by htsang            #+#    #+#             */
/*   Updated: 2023/09/23 23:45:07 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"

class Form
{
  public:
    Form();
    Form(std::string name, int gradeSign, int gradeExecute);
    Form(const Form& copy);
    virtual ~Form();
  
    Form& operator=(const Form& copy);

    void  beSigned(Bureaucrat& bureaucrat);

    std::string const getName() const;
    bool              getSigned() const;
    int               getGradeSign() const;
    int               getGradeExecute() const;

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
  
  private:
    std::string const name_;
    bool              signed_;
    int const         gradeSign_;
    int const         gradeExecute_;
};

std::ostream& operator<<(std::ostream& os, const Form& form);