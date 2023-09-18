/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tokenizer.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 23:21:18 by htsang            #+#    #+#             */
/*   Updated: 2023/09/17 23:27:05 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "TokenizerBase.hpp"

template <typename Token>
class Tokenizer : public TokenizerBase
{
  public:
    Tokenizer()
      : TokenizerBase(),
        tokens_(Stack<Token *>()) {}
    
    Tokenizer(std::string &input)
      : TokenizerBase(input),
        tokens_(Stack<Token *>()) {}

    Tokenizer(const Tokenizer& value)
      : TokenizerBase(value),
        tokens_(value.tokens_) {}

    ~Tokenizer()
    {
      for (size_t i = 0; i < tokens_.size(); i++)
      {
        delete tokens_.pop();
      }
    };

    const Tokenizer& operator=(const Tokenizer& value)
    {
      if (this == &value)
        return *this;
      TokenizerBase::operator=(value);
      tokens_ = value.tokens_;
      return *this;
    }

    virtual Token*  next() = 0;
    void    put_back(Token *token)
    {
      tokens_.push(token);
    }

  protected:
    Stack<Token *>  tokens_;
};