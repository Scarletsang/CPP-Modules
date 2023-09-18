/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedParser.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:32:55 by htsang            #+#    #+#             */
/*   Updated: 2023/09/18 11:43:16 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "fixedparser/parser/Parser.hpp"
#include "fixedparser/FixedToken.hpp"
#include "Fixed.hpp"

class FixedParser : public Parser<FixedToken, Fixed>
{
  public:
    FixedParser(const FixedParser& value);
    FixedParser(Tokenizer<FixedToken> &tokenizer);
    ~FixedParser();
    const FixedParser& operator=(const FixedParser& value);

    Fixed parse();
  
  protected:
    Fixed parse_expression();
    Fixed parse_term();
    Fixed parse_factor();

    Fixed process_number(FixedToken *token);

    void  handle_error(int error_code);

    FixedToken::Type  last_operator_type_;
  
  private:
    FixedParser();
};
