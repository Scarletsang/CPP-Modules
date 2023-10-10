/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 01:32:30 by htsang            #+#    #+#             */
/*   Updated: 2023/10/10 16:40:47 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <string>
#include <iostream>
#include <fstream>

#include "../AForm.hpp"
#include "../Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
  : AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
  : AForm("ShrubberyCreationForm", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
  : AForm(copy) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
  if (this == &copy)
    return (*this);
  return (*this);
}

void  ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
  checkExecutable(executor);
  std::string file_name = getTarget() + "_shrubbery";
  std::fstream file(file_name.c_str(), std::fstream::out | std::fstream::trunc);

  if (!file.is_open())
    std::cerr << "Error: " << getTarget() << "_shrubbery" << " could not be opened nor created." << std::endl;
  else
  {
    file << "      /\\      " << std::endl;
    file << "     /\\*\\     " << std::endl;
    file << "    /\\O\\*\\    " << std::endl;
    file << "   /*/\\/\\/\\   " << std::endl;
    file << "  /\\O\\/\\*\\/\\  " << std::endl;
    file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
    file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file.close();
  }
}
