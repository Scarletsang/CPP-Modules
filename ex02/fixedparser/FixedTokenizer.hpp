/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedTokenizer.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:25:47 by htsang            #+#    #+#             */
/*   Updated: 2023/09/17 23:44:53 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "parser/tokenizer/Tokenizer.hpp"
#include "FixedToken.hpp"

class FixedTokenizer : public Tokenizer<FixedToken>
{
  public:
    FixedTokenizer();
    FixedTokenizer(const FixedTokenizer& value);
    ~FixedTokenizer();
    const FixedTokenizer& operator=(const FixedTokenizer& value);

    FixedToken *next();
  
  private:
    FixedToken *tokenize_number();
    FixedToken *tokenize_one(FixedToken::Type type);
};
