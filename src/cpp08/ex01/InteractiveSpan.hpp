/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InteractiveSpan.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:19:43 by htsang            #+#    #+#             */
/*   Updated: 2023/12/04 22:24:09 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "interactive/Prompt.hpp"
#include "interactive/Data.hpp"
#include "Span.hpp"

class InteractiveSpan : public interactive::Data
{
  public:
    InteractiveSpan();
    InteractiveSpan(const InteractiveSpan& InteractiveSpan);
    virtual ~InteractiveSpan();
    const InteractiveSpan& operator=(const InteractiveSpan& InteractiveSpan);

    void  generate(int size);
      void  addNumber(int number);
    void  print() const;
    void  status() const;

    /**
     * @brief Get a number from the user input and then add it to span
    */
    int   addNumber();

  private:
    Span                span_;
    interactive::Prompt subprompt_;
};

int GetNumberAction(const std::string& input, interactive::PrimitiveData<int>& data);
