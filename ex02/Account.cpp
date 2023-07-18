/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:23:40 by htsang            #+#    #+#             */
/*   Updated: 2023/07/18 16:56:28 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <ctime>

#include <iostream>

void  Account::_displayTimestamp(void)
{
  std::time_t epoch_time = std::time(NULL);
  std::tm *calender_time = std::localtime(&epoch_time);
  char  printable_time[16];

  printable_time[15] = '\0';
  std::strftime(printable_time, 16, "%Y%m%d_%H%M%S", calender_time);
  std::cout << "[" << printable_time << "] ";
}

int Account::getNbAccounts(void)
{
  return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
  return Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
  return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
  return Account::_totalNbWithdrawals;
}

void  Account::displayAccountsInfos(void)
{
  _displayTimestamp();
  std::cout << "accounts:" << getNbAccounts() << ";";
  std::cout << "total:" << getTotalAmount() << ";";
  std::cout << "deposits:" << getNbDeposits() << ";";
  std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
  // instance data members
  this->_accountIndex = _nbAccounts;
  this->_amount = initial_deposit;
  this->_nbDeposits = 0;
  this->_nbWithdrawals = 0;

  // class data memebers
  _nbAccounts++;
  _totalAmount += initial_deposit;

  // display
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(void)
{
  // class data memebers
  _nbAccounts--;
  _totalAmount -= this->_amount;

  // display
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << this->_amount << ";closed" << std::endl;
}

void  Account::makeDeposit(int deposit)
{
  // display for information before deposit
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "p_amount:" << this->_amount << ";";
  std::cout << "deposit:" << deposit << ";";

  // class data memebers
  _totalAmount += deposit;
  _totalNbDeposits++;

  // instance data members
  this->_amount += deposit;
  this->_nbDeposits++;

  // display for information after deposit
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool  Account::makeWithdrawal(int withdrawal)
{
  // display for information before deposit
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "p_amount:" << this->_amount << ";";
  if (this->_amount < withdrawal)
  {
    std::cout << "withdrawal:refused" << std::endl;
    return false;
  }
  else
  {
    std::cout << "withdrawal:" << withdrawal << ";";
  }

  // class data memebers
  _totalAmount -= withdrawal;
  _totalNbWithdrawals++;

  // instance data members
  this->_amount -= withdrawal;
  this->_nbWithdrawals++;

  // display for information after deposit
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
  return true;
}

int		Account::checkAmount(void) const
{
  return _amount;
}

void  Account::displayStatus(void) const
{
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "deposits:" << this->_nbDeposits << ";";
  std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}
