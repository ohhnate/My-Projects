// Lab 5 -- C++ (re)fresher, pt 5
//
// Programmer name: Samuel Fuller
// Date completed:  24 Sep 2019

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "bank_account.h"

TEST_CASE("BankAccount class") {
  BankAccount empty;
  CHECK(empty.getBalance() == 0.0);
  CHECK(empty.getAccountNumber() == 0);
  BankAccount newAccount(1);
  CHECK(newAccount.getAccountNumber() == 1);

  BankAccount myAccount(1.50, 2);
  CHECK(myAccount.getAccountNumber() == 2);
  CHECK(myAccount.getBalance() == 1.50);
  myAccount.deposit(10.00);
  myAccount.deposit(0.00);
  CHECK(myAccount.getBalance() == 11.50);
  myAccount.withdraw(5.00);
  CHECK(myAccount.getBalance() == 6.50);

  //Check overdrawing returns false
  CHECK(myAccount.withdraw(100.00) == false);
  CHECK(myAccount.getBalance() == 6.50);

  CHECK(myAccount.toString() == "Account #2, Current balance $6.50");
  CHECK(empty.toString() == "Account #0, Current balance $0.00");
}
