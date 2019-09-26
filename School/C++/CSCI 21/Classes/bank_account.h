#pragma once

#include <sstream>
#include <string>
using std::ios;
using std::string;
using std::stringstream;

class BankAccount {
public:
  // Initialize a BankAccount with balance=0.0 and accountNumber=0
  BankAccount();

  // Initialize a BankAccount with balance=0.0 and accountNumber=accountNumber
  BankAccount(unsigned int accountNumber);

  // Initialize a BankAccount with balance=balance and accountNumber=accountNumber
  BankAccount(double balance, unsigned int accountNumber);

  // Deposit funds. Balance will increase by amount.
  void deposit(double amount);

  // If amount <= balance, reduce balance by amount and return true.
  // Otherwise return false.
  bool withdraw(double amount);

  // Return the balance.
  double getBalance();

  // Return the accountNumber.
  unsigned int getAccountNumber();

  // Example: "Account #12345, Current balance $99.35"
  // Use the "magic formula" to format the balance.
  string toString();

private:
  double balance;
  unsigned int accountNumber;
};
