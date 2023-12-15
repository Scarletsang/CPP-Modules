/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:49:26 by htsang            #+#    #+#             */
/*   Updated: 2023/12/06 15:50:12 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Error
{
  public:
    enum kErrorCode
    {
      kOk,
      kInvalidNumber,
      kInvalidOperation,
      kInvalidOperand,
      kStackEmpty,
      kAmbiguous
    };
    Error();
    Error(kErrorCode code);
    Error(Error const& other);
    Error& operator=(Error const& other);
    ~Error();
  
    kErrorCode code() const;

  private:
    kErrorCode code_;
};

std::ostream& operator<<(std::ostream& os, Error const& e);
