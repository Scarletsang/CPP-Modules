/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:03:51 by htsang            #+#    #+#             */
/*   Updated: 2023/11/11 00:08:36 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <exception>
#include <utility>

#include "Date.hpp"

namespace bitcoin_exchange
{
  class Database
  {
    public:
      enum  kErrorCode
      {
        kNoError = 0,
        kInvalidDate,
        kNegativeRate,
        kOutOfRangeRate
      };
      typedef std::map<Date, float>::const_iterator const_iterator;

      Database();
      Database(Database const& other);
      ~Database();

      Database&  operator=(Database const& other);

      enum  kErrorCode        set_entry(Date date, float rate);
      enum  kErrorCode        set_entry(std::pair<Date, float> entry);
      float                   get_rate(Date date) const;
      std::pair<Date, float>  get_closest_entry(Date date) const;

      bool                    is_empty() const;
      size_t                  size() const;

      const_iterator          begin() const;
      const_iterator          end() const;

      class NoRateException : public std::exception
      {
        public:
          virtual const char* what() const throw();
      };
    
    private:
      std::map<Date, float>  rates_;
  };
} // namespace bitcoin_exchange
