/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 01:54:43 by htsang            #+#    #+#             */
/*   Updated: 2023/09/24 01:55:16 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#include "../AForm.hpp"
#include "../Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
  public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm& copy);
    virtual ~PresidentialPardonForm();

    PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);

    virtual void  execute(Bureaucrat const & executor) const;
};
