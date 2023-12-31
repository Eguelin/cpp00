/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:23:08 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/22 00:28:58 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

/* ************************************************************************** */
/*                                   Getters                                  */
/* ************************************************************************** */

int	Account::getNbAccounts( void ) {return (Account::_nbAccounts);}

int	Account::getTotalAmount( void ) {return (Account::_totalAmount);}

int	Account::getNbDeposits( void ) {return (Account::_totalNbDeposits);}

int	Account::getNbWithdrawals( void ) {return (Account::_totalNbWithdrawals);}

/* ************************************************************************** */
/*                       Public static member functions                       */
/* ************************************************************************** */

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

Account::Account( int initial_deposit )
{
	this->_nbAccounts++;
	this->_totalAmount += initial_deposit;
	this->_accountIndex = this->_nbAccounts - 1;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	Account::_displayTimestamp();

	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

/* ************************************************************************** */
/*                           Public member functions                          */
/* ************************************************************************** */

void	Account::makeDeposit( int deposit )
{
	this->_nbDeposits++;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount + deposit << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;

	this->_totalAmount += deposit;
	this->_amount += deposit;
	this->_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();

	if (withdrawal <= this->_amount)
	{
		this->_nbWithdrawals++;

		std::cout << "index:" << this->_accountIndex << ";";
		std::cout << "p_amount:" << this->_amount << ";";
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << this->_amount - withdrawal << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;

		this->_totalAmount -= withdrawal;
		this->_amount -= withdrawal;
		this->_totalNbWithdrawals++;
	}
	else
	{
		std::cout << "index:" << this->_accountIndex << ";";
		std::cout << "p_amount:" << this->_amount << ";";
		std::cout << "withdrawal:refused" << std::endl;

		return (false);
	}

	return (true);
}

int		Account::checkAmount( void ) const
{
	return(this->_amount);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

/* ************************************************************************** */
/*                       Private static member variables                      */
/* ************************************************************************** */

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/* ************************************************************************** */
/*                       Private static member functions                      */
/* ************************************************************************** */

void	Account::_displayTimestamp( void )
{
	time_t now = time(0);
    char timestamp[19];

    std::strftime(timestamp, sizeof(timestamp), "[%Y%m%d_%H%M%S] ", std::localtime(&now));

	std::cout << timestamp ;
}


