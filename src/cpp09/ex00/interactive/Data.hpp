/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:53:54 by htsang            #+#    #+#             */
/*   Updated: 2023/12/05 21:59:28 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace interactive
{
  class Data
  {
    public:
      Data();
      Data(const Data& promptdata);
      virtual ~Data();
      const Data& operator=(const Data& promptdata);
  };

  template <typename T>
  class PrimitiveData : public Data
  {
    public:
      PrimitiveData();
      PrimitiveData(const T& data);
      PrimitiveData(const PrimitiveData& promptdata);
      virtual ~PrimitiveData();
      const PrimitiveData& operator=(const PrimitiveData& promptdata);

      T&  unwrap();

    private:
      T  data_;
  };

  /////////////////////////////////////////////////////
  ////////////   template implementation   ////////////
  /////////////////////////////////////////////////////

  template <typename T>
  PrimitiveData<T>::PrimitiveData()
    : Data(), data_() {}

  template <typename T>
  PrimitiveData<T>::PrimitiveData(const T& data)
    : Data(), data_(data) {}

  template <typename T>
  PrimitiveData<T>::PrimitiveData(const PrimitiveData& promptdata)
    : Data(promptdata), data_(promptdata.data_) {}

  template <typename T>
  PrimitiveData<T>::~PrimitiveData() {}

  template <typename T>
  const PrimitiveData<T>& PrimitiveData<T>::operator=(const PrimitiveData& promptdata)
  {
    if (this != &promptdata)
    {
      Data::operator=(promptdata);
      data_ = promptdata.data_;
    }
    return *this;
  }

  template <typename T>
  T&  PrimitiveData<T>::unwrap()
  {
    return data_;
  }

} // namespace interactive


