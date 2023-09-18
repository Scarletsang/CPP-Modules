/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:41:28 by htsang            #+#    #+#             */
/*   Updated: 2023/09/18 13:42:52 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./Tokenizer.hpp"

template <typename Token, typename Result>
class Parser
{
  public:
    Parser(Tokenizer<Token> &tokenizer)
      : tokenizer_(&tokenizer),
        syntax_error_(false),
        malloc_error_(false) {}

    Parser(const Parser& value)
      : tokenizer_(value.tokenizer_),
        stack_(value.stack_),
        syntax_error_(value.syntax_error_),
        malloc_error_(value.malloc_error_),
        result_(value.result_) {}

    virtual ~Parser() {
      while (!stack_.is_empty())
      {
        delete stack_.pop();
      }
    }

    const Parser& operator=(const Parser& value)
    {
      if (this == &value)
        return *this;
      tokenizer_ = value.tokenizer_;
      stack_ = value.stack_;
      syntax_error_ = value.syntax_error_;
      malloc_error_ = value.malloc_error_;
      result_ = value.result_;
      return *this;
    }

    bool  has_tokenizer_error() const
    {
      return !tokenizer_->is_valid();
    }

    bool  has_malloc_error() const
    {
      return malloc_error_;
    }

    bool  has_syntax_error() const
    {
      return syntax_error_;
    }

    bool  has_error() const
    {
      return has_tokenizer_error() || has_malloc_error() || has_syntax_error();
    }

    bool  is_end() const
    {
      return tokenizer_->is_end();
    }

    void  set_tokenizer(Tokenizer<Token> &tokenizer)
    {
      tokenizer_ = &tokenizer;
    }

    virtual Result parse() = 0;
  
  protected:
    int  tokenize()
    {
      Token *token = tokenizer_->next();
      if (!token)
      {
        malloc_error_ = true;
        return EXIT_FAILURE;
      }
      else if (!tokenizer_->is_valid())
      {
        syntax_error_ = true;
        delete token;
        return EXIT_FAILURE;
      }
      else
      {
        stack_.push(token);
        return EXIT_SUCCESS;
      }
    }

    virtual void  handle_error(int error_code) = 0;

    Result parse_error(int error_code)
    {
      handle_error(error_code);
      return Result();
    }

    Tokenizer<Token>  *tokenizer_;
    Stack<Token *>    stack_;
    bool              syntax_error_;
    bool              malloc_error_;
    Result            result_;
  
  private:
    Parser() {};
};
