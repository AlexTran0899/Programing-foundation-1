//
// Created by Alex Tran on 11/16/22.
//

#include "Account.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

Account::Account()
{
  _firstName     = "";
  _lastName      = "";
  _PIN           = "";
  _accountNumber = "";
}

Account::Account(const string firstName, const string lastName, const string PIN, const string accountNumber)
{
  _firstName     = firstName;
  _lastName      = lastName;
  _PIN           = PIN;
  _accountNumber = accountNumber;
}

Account:: Account(const Account & copy){
  _firstName     = copy._firstName;
  _lastName      = copy._lastName;
  _PIN           = copy._PIN;
  _accountNumber = copy._accountNumber;
}

Account::~Account(){
  
}

string Account::getAccountNumber() const {
  return _accountNumber;
}

string Account::getFirstName() const {
  return _firstName;
};

string Account::getPIN() const{
  return _PIN;
};