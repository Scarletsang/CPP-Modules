/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:11:35 by htsang            #+#    #+#             */
/*   Updated: 2023/11/21 16:13:06 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>
#include <iostream>
#include <string>

class Form;

class Bureaucrat
{
  public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(Bureaucrat const &obj);
    ~Bureaucrat();

    Bureaucrat &operator=(Bureaucrat const &obj);

    void  signForm(Form& form);

    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException : public std::exception
    {
      public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
      public:
        const char *what() const throw();
    };
  
  private:
    std::string const name_;
    int               grade_;
};

std::ostream&  operator<<(std::ostream& os, Bureaucrat const &obj);
