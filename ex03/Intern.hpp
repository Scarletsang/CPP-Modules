/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:54:45 by htsang            #+#    #+#             */
/*   Updated: 2023/10/10 18:01:52 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

#include <string>

class Intern
{
  public:
    Intern();
    Intern(const Intern& copy);
    ~Intern();

    Intern& operator=(const Intern& copy);

    AForm*  makeForm(std::string form_name, std::string target);
  
  protected:
    static const std::string form_names_[3];
};
