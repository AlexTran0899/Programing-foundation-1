#include "Account.h"
#include "Transaction.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

Account selectedAccount;
string selectedUser = "Donna";

// prototype
void accountRead(const string fileName, vector<Account> &accounts);
void encryptedRead(const string fileName, vector<Account> &accounts);
string getFirstName(string accountNum, vector<Account> &accounts);
void transactionRead(const string filename, vector<Transaction> &transactions);
void transactionWrite(const string filename, vector<Transaction> &transactions);

int main() {
  vector<Account> accounts;
  vector<Transaction> transactions;

  accountRead("accounts.txt", accounts);
  transactionRead("encryptedTransactions.txt", transactions);

  for (int i = 0; i < accounts.size(); i++) {
    if (accounts[i].getFirstName() == selectedUser) {
      selectedAccount = accounts[i];
      break;
    }
  }
  transactionWrite("decryptedTransactions.txt", transactions);
}

void accountRead(const string fileName, vector<Account> &accounts) {
  string lineString;
  istringstream inSS;
  string firstName;
  string lastName;
  string PIN;
  string accountNumber;
  ifstream inFS(fileName);

  if (inFS.is_open()) {
    while (getline(inFS, lineString)) {
      inSS.clear();
      inSS.str(lineString);
      inSS >> firstName >> lastName >> PIN >> accountNumber;
      Account tempAccount(firstName, lastName, PIN, accountNumber);
      accounts.push_back(tempAccount);
    }
  }
  inFS.close();
}

void transactionRead(const string filename, vector<Transaction> &transactions) {
  string lineString;
  istringstream inSS;
  string fromAccountNumber;
  string toAccountNumber;
  string amount;
  ifstream inFS(filename);

  if (inFS.is_open()) {
    while (getline(inFS, lineString)) {
      inSS.clear();
      inSS.str(lineString);
      inSS >> fromAccountNumber >> toAccountNumber >> amount;

      Transaction tempTransaction(fromAccountNumber, toAccountNumber, amount);
      transactions.push_back(tempTransaction);
      tempTransaction.print();
    }
  }
  inFS.close();
}

void transactionWrite(const string filename,
                      vector<Transaction> &transactions) {
  ofstream MyFile(filename);
  string selectedUserAccountNumber = selectedAccount.getAccountNumber();
  string selectedUserPinNumber = selectedAccount.getPIN();

  for (int i = 0; i < transactions.size(); i++) {
    if (transactions[i].decrypt(selectedUserAccountNumber,
                                selectedUserPinNumber)) {
      MyFile << transactions[i].getFromAccountNumber() << " ";
      MyFile << transactions[i].getToAccountNumber() << " ";
      MyFile << transactions[i].getAmount() << endl;
    }
  }
  MyFile.close();
}