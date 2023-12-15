/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/10/29 17:53:16 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include <iostream>
#include <string>

#include "identifier.hpp"

namespace noninteractive
{
  int Run()
  {
    Base* base = identifier::generate();
    Base& baseRef = *base;

    identifier::identify(base);
    identifier::identify(baseRef);

    delete base;

    return EXIT_SUCCESS;
  }
} // namespace noninteractive

int main(void)
{
  return noninteractive::Run();;
}
