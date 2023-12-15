/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifier.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:34:08 by htsang            #+#    #+#             */
/*   Updated: 2023/10/29 17:59:02 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identifier.hpp"

#include <cstdlib>
#include <ctime>

#include <iostream>
#include <exception>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

namespace identifier
{
  Base* generate(void)
  {
    srand(time(NULL));
  
    int random = rand() % 3;

    switch (random)
    {
      case 0:
        std::cout << "A is generated" << std::endl;
        return new A();
      case 1:
        std::cout << "B is generated" << std::endl;
        return new B();
      case 2:
        std::cout << "C is generated" << std::endl;
        return new C();
      default:
        break;
    }
    return NULL;
  }

  void  identify(Base* p)
  {
    std::cout << "identify by pointer: ";
    if (dynamic_cast<A*>(p))
      std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
      std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
      std::cout << "C" << std::endl;
  }

  void  identify(Base& p)
  {
    std::cout << "identify by reference: ";
    try
    {
      static_cast<void>(dynamic_cast<A&>(p));
      std::cout << "A" << std::endl;
      return ;
    }
    catch (std::exception& bc) {}
    try
    {
      static_cast<void>(dynamic_cast<B&>(p));
      std::cout << "B" << std::endl;
      return ;
    }
    catch (std::exception& bc) {}
    try
    {
      static_cast<void>(dynamic_cast<C&>(p));
      std::cout << "C" << std::endl;
      return ;
    }
    catch (std::exception& bc) {
      std::cout << "Un-registered subclass of Base class" << std::endl;
    }
  }
} // namespace identifier
