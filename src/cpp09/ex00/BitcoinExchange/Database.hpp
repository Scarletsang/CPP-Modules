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

#include "Result.hpp"
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
        kOutOfRangeRate,
        kEmptyDatabase
      };
      typedef std::map<Date, float>::const_iterator const_iterator;
      typedef Result<float, Database::kErrorCode>                   RateResult;
      typedef Result<std::pair<Date, float>, Database::kErrorCode>  EntryResult;

      Database();
      Database(Database const& other);
      ~Database();

      Database&         operator=(Database const& other);

      enum  kErrorCode  set_entry(Date date, float rate);
      enum  kErrorCode  set_entry(std::pair<Date, float> entry);
      RateResult        get_rate(Date date) const;
      EntryResult       get_closest_entry(Date date) const;

      bool              is_empty() const;
      size_t            size() const;

      const_iterator    begin() const;
      const_iterator    end() const;

      void              print_error(enum kErrorCode error_code) const;
    
    private:
      std::map<Date, float>  rates_;
  };
} // namespace bitcoin_exchange
