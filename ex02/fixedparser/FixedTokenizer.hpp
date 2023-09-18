/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedTokenizer.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:25:47 by htsang            #+#    #+#             */
/*   Updated: 2023/09/18 11:42:53 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "fixedparser/parser/Tokenizer.hpp"
#include "fixedparser/FixedToken.hpp"

class FixedTokenizer : public Tokenizer<FixedToken>
{
  public:
    FixedTokenizer();
    FixedTokenizer(std::string &string);
    FixedTokenizer(const FixedTokenizer& value);
    ~FixedTokenizer();
    const FixedTokenizer& operator=(const FixedTokenizer& value);

    FixedToken *next();
  
  private:
    FixedToken *tokenize_number();
    FixedToken *tokenize_one(FixedToken::Type type);
};
