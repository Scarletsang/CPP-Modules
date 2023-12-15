/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:54:23 by htsang            #+#    #+#             */
/*   Updated: 2023/09/15 20:11:10 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Brain
{
  public:
    Brain();
    Brain(const Brain &copy);
    ~Brain();
    Brain &operator=(const Brain &op);

    std::string getIdea(int index) const;
    void setIdea(int index, std::string idea);
  
  private:
    std::string ideas[100];
};
