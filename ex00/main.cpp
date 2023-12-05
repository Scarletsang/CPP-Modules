/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:44:18 by htsang            #+#    #+#             */
/*   Updated: 2023/12/05 23:00:48 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include <iostream>
#include <string>

#include "interactive/Prompt.hpp"
#include "BitcoinExchange/Parser.hpp"
#include "BitcoinExchange.hpp"
#include "Date.hpp"

namespace interactive
{
  typedef PrimitiveData<BitcoinExchange> InteractiveData;
  typedef PrimitiveData<Date> DateData;

  int GetDateAction(const std::string& input, DateData& date_data)
  {
    bitcoin_exchange::ParserEnv env(input.begin(), input.end());
    bitcoin_exchange::DateParseResult result = bitcoin_exchange::ParseDate(env);
    if (result.is_ok())
    {
      date_data.unwrap() = result.value();
      return EXIT_SUCCESS;
    }
    else
      return EXIT_FAILURE;
  }

  int CompareEntryAction(const std::string& input, InteractiveData& data)
  {
    BitcoinExchange::kErrorCode error_code = data.unwrap().compare_entry_from_line(input, "|");
    if (error_code != BitcoinExchange::kNoError)
    {
      data.unwrap().print_error(error_code, input);
      return EXIT_FAILURE;
    }
    else
      return EXIT_SUCCESS;
  }

  int CompareAction(const std::string&, InteractiveData& data)
  {
    return RunActionFunc(CompareEntryAction, data,
      "Enter an entry(year-month-day | number)", "Invalid entry. Try again: ");
  }

  int QueryAction(const std::string&, InteractiveData& data)
  {
    DateData date_data;

    if (RunActionFunc(GetDateAction, date_data,
      "Enter a date(year-month-day)", "Invalid date. Try again: "))
      return EXIT_FAILURE;
    const bitcoin_exchange::Database& db = data.unwrap().get_database();

    std::pair<Date, float> entry = db.get_closest_entry(date_data.unwrap());
    std::cout << entry.first << "," << entry.second << std::endl;
    return EXIT_SUCCESS;
  }

  int PrintAction(const std::string&, InteractiveData& data)
  {
    const bitcoin_exchange::Database& db = data.unwrap().get_database();

    for (bitcoin_exchange::Database::const_iterator it = db.begin(); it != db.end(); ++it)
    {
      std::cout << it->first << ": " << it->second << std::endl;
    }
    return EXIT_SUCCESS;
  }

  int Exit(const std::string&, InteractiveData&)
  {
    return EXIT_FAILURE;
  }

  int Run()
  {
    Prompt          prompt;

    prompt.set_prompt("What do you want to do?");
    prompt.set_reprompt("Invalid input. Try again: ");
    prompt.register_action("compare", Action<InteractiveData, CompareAction>);
    prompt.register_action("query", Action<InteractiveData, QueryAction>);
    prompt.register_action("print", Action<InteractiveData, PrintAction>);
    prompt.register_action("exit", Action<InteractiveData, Exit>);
    {
      InteractiveData data;
      BitcoinExchange& bitcoin_exchange = data.unwrap();

      if (bitcoin_exchange.entries_from_file("./data.csv", ",", true))
        return EXIT_FAILURE;
      prompt.shell(data);
    }
    return EXIT_SUCCESS;
  }
} // namespace interactive

namespace noninteractive
{
  int Run(const char *filename)
  {
    BitcoinExchange bitcoin_exchange;

    bitcoin_exchange.entries_from_file("./data.csv", ",", false);
    return bitcoin_exchange.compare_entries_from_file(filename, "|");
  }
} // namespace noninteractive

int main(int argc, const char** argv)
{
  if (argc == 2)
  {
    if (std::string(argv[1]) == "-i")
      return interactive::Run();
    else
      return noninteractive::Run(argv[1]);
  }
  else
  {
    std::cerr << "Usage: " << argv[0] << " [ filename | -i ]" << std::endl;
    return EXIT_FAILURE;
  }
}
