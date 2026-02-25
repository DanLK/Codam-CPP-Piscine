#include "Account.hpp"
#include <iostream>
#include <ctime>

Account::Account(int intial_deposit){
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = intial_deposit;
	Account::_nbAccounts += 1;
	Account::_totalAmount += this->_amount;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount <<
	";created" << std::endl;
}

int	Account::getNbAccounts( void ){
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void ){
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void ){
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void ){
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ){
	_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:" <<
	Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits <<
	";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ){
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount <<
	";deposit:" << deposit;
	this->_amount += deposit;
	this->_nbDeposits += 1;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;
	std::cout << ";amount:" << this->_amount << ";nb_deposits:" <<
	this->_nbDeposits << std::endl;
}

int		Account::checkAmount( void ) const{
	return this->_amount;
}

bool	Account::makeWithdrawal( int withdrawal ){
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount <<
	";withdrawal:";
	if (this->_amount >= withdrawal){
		this->_amount -= withdrawal;
		this->_nbWithdrawals += 1;
		Account::_totalNbWithdrawals += 1;
		Account::_totalAmount -= withdrawal;
		std::cout << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" <<
		this->_nbWithdrawals << std::endl;
		return true;
	}
	std::cout << "refused" << std::endl;
	return false;
}

void	Account::displayStatus( void ) const{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount <<
	";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals <<
	std::endl;
}

void	Account::_displayTimestamp( void ){
	std::time_t timestamp = time(NULL);
	struct tm datetime = *localtime(&timestamp);

	char	time_output[18];

	std::strftime(time_output, 18, "[%G%m%d_%H%M%S]", &datetime);
	
	std::cout << time_output;

}

Account::~Account( void ){
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount <<
	";closed" << std::endl;
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;