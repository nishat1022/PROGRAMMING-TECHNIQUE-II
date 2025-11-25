// BankAccount.cpp
#include "BankAccount.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using std::cout;
using std::endl;

//
// Private helpers
//
bool BankAccount::isValidAmount(double amount) const {
    return amount > 0.0;
}

std::string BankAccount::formatCurrency(double amount) const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << amount;
    return oss.str();
}

//
// ctors / dtor
//
BankAccount::BankAccount() : owner(""), accountNumber(0), balance(0.0) {}

BankAccount::BankAccount(const std::string &ownerName, int acctNum, double initialBalance)
    : owner(ownerName), accountNumber(acctNum), balance(initialBalance) {}

BankAccount::BankAccount(const BankAccount &other)
    : owner(other.owner), accountNumber(other.accountNumber), balance(other.balance) {
    cout << "Copy constructor called." << endl;
}

BankAccount::~BankAccount() {
    // No dynamic resources; nothing special to do
}

//
// Public interface
//
void BankAccount::deposit(double amount) {
    if (isValidAmount(amount)) {
        balance += amount;
    }
}

bool BankAccount::withdraw(double amount) {
    if (isValidAmount(amount) && amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
}

double BankAccount::getBalance() const {
    return balance;
}

void BankAccount::display() const {
    cout << "Owner: " << owner << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: RM" << formatCurrency(balance) << endl;
}

void BankAccount::setDetails(const std::string &ownerName, int acctNum) {
    owner = ownerName;
    accountNumber = acctNum;
}
