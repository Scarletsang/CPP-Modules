/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reader.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 23:41:22 by htsang            #+#    #+#             */
/*   Updated: 2023/11/12 00:33:16 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename Data, typename Env>
class Reader
{
  public:
    typedef Data (*ReaderFunction)(Env& env);
    Reader(ReaderFunction reader_function, Env& env);
    Reader(Reader const& other);
    Reader& operator=(Reader const& other);
    ~Reader();

    Data  operator()() const;

    template <typename Data2>
    Reader<Data2, Env>  chain(Reader<Data2, Env> (*f)(Data, Env&)) const;

  private:
    ReaderFunction  reader_function_;
    Env&            env;
};

/////////////////////////////////////////////////////
////////////   template implementation   ////////////
/////////////////////////////////////////////////////   

template <typename Data, typename Env>
Reader<Data, Env>::Reader(ReaderFunction reader_function, Env& env)
  : reader_function_(reader_function), env_(env) {}

template <typename Data, typename Env>
Reader<Data, Env>::Reader(Reader<Data, Env> const& other)
  : reader_function_(other.reader_function_), env_(other.env_) {}

template <typename Data, typename Env>
Reader<Data, Env>& Reader<Data, Env>::operator=(Reader<Data, Env> const& other)
{
  if (this != &other)
  {
    reader_function_ = other.reader_function_;
    env_ = other.env_;
  }
  return *this;
}

template <typename Data, typename Env>
Reader<Data, Env>::~Reader() {}

template <typename Data, typename Env>
Data  Reader<Data, Env>::operator()() const
{
  return reader_function_(env_);
}

template <typename Data, typename Env>
template <typename Data2>
Reader<Data2, Env>  Reader<Data, Env>::chain(Reader<Data2, Env> (*f)(Data, Env&)) const
{
  return f(reader_function_(), env_);
}
