#include <iostream>
#include <ctime>

#include "Account.hpp"


int	Account::getNbAccounts( ) {

	return Account::_nbAccounts;
};



int	Account::getTotalAmount( ) {

	return Account::_totalAmount;
};


void	Account::_displayTimestamp( void ) {

	time_t rawtime;
	struct tm * timeinfo;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );

	std::cout << "[";
	std::cout << timeinfo->tm_year + 1900;
	std::cout << timeinfo->tm_mon + 1;
	std::cout << timeinfo->tm_mday;
	std::cout << "_";
	std::cout << timeinfo->tm_hour;
	std::cout << timeinfo->tm_min;
	std::cout << timeinfo->tm_sec;
	std::cout << "] ";
};



int	Account::getNbDeposits( ) {

	return Account::_totalNbDeposits;
};



int	Account::getNbWithdrawals( ) {

	return Account::_totalNbWithdrawals;
};



void	Account::displayAccountsInfos( ) {

	_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals;
	std::cout << std::endl;

	return ;
};

Account::Account( int initial_deposit ) {
	

	_accountIndex = Account::_nbAccounts;

	_amount = initial_deposit;
	Account:: _totalAmount	+= _amount;

	_nbDeposits = 0;
	_nbWithdrawals = 0;


	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;

	Account::_nbAccounts += 1;
}

Account::~Account( ) {

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;

	Account::_nbAccounts -= 1;
};



Account::Account( ) {

	return ;
};


void	Account::makeDeposit( int deposit ) {

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";

	_amount += deposit;
	_nbDeposits += 1;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;

	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
};


bool	Account::makeWithdrawal( int withdrawal ) {

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";

	if ( _amount - withdrawal < 0 ) {
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}

	std::cout << "withdrawal:" << withdrawal << ";";

	_amount -= withdrawal;
	_nbWithdrawals += 1;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals += 1;

	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;

	return true;
};


int		Account::checkAmount( void ) const {

	return _amount;
};


void	Account::displayStatus( void ) const {

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
};

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;