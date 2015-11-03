#include <iostream>
#include "Account.class.hpp"

int     Account::getNbAccounts( void ) {
    return Account::_nbAccounts; }

int     Account::getTotalAmount( void ) {
    return Account::_totalAmount; }
int     Account::getNbDeposits( void ) {
    return Account::_totalNbDeposits; }

int     Account::getNbWithdrawals( void ) {
    return Account::_totalNbWithdrawals; }

void    Account::displayAccountsInfos( void ) {
    Account::_displayTimestamp;
    std::cout << "accounts:" << Account::_nbAccounts
        << ";total:" << Account::_totalAmount
        << ";deposists:" << Account::_totalNbDeposits
        << ";withdrawals:" << Account::_totalNbWithdrawals
        << std::endl; }

Account::Account( int initial_deposit ) {
    this->_accountIndex = Account::_nbAccounts;
    Account::_nbAccounts += 1;
    this->_amount = initial_deposit;
    Account::_totalAmount += initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    std::cout << "index:" << this->_accountIndex
        << ";amount:" << this->_amount
        << ";created" << std::endl; }

Account::~Account( void ) {}

void    Account::makeDeposit( int deposit ) {
    this->_amount += deposit;
    this->_nbDeposits += 1;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits += 1; }

bool    Account::makeWithdrawal( int withdrawal ) {
    if (withdrawal < this->_amount) {
        this->_amount -= withdrawal;
        this->_nbWithdrawals += 1;
        Account::_totalAmount -= withdrawal;
        Account::_totalNbWithdrawals += 1;
        return (true); }
    else {
        return (false); }}

int     Account::checkAmount( void ) const {
    return (this->_amount); }

void    Account::displayStatus( void ) const {
    std::cout << "index:" << this->_accountIndex
        << ";amount:" << this->_amount
        << ";deposits:" << this->_nbDeposits
        << ";withdrawals:" << this->_nbWithdrawals
        << std::endl; }

void	_displayTimestamp( void ) {}

Account::Account( void ) {
    this->_accountIndex = Account::_nbAccounts;
    Account::_nbAccounts += 1;
    this->_amount = 0;
    Account::_totalAmount += 0;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    std::cout << "index:" << this->_accountIndex
        << ";amount:" << this->_amount
        << ";created" << std::endl; }
