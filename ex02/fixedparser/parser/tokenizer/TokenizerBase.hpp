/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TokenizerBase.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:23:13 by htsang            #+#    #+#             */
/*   Updated: 2023/09/18 08:05:05 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../Stack.hpp"

#include <string>

class TokenizerBase
{
  public:
    TokenizerBase();
    TokenizerBase(std::string string);
    TokenizerBase(const TokenizerBase& value);
    ~TokenizerBase();
    const TokenizerBase& operator=(const TokenizerBase& value);

    bool    is_valid() const;
    bool    is_end() const;

    void    set_string(std::string string);
  
  protected:
    std::string     string_;
    size_t          pos_;
    bool            is_valid_;
};
