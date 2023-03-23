#include "BankAccount.h"

std::string name;
std::string acctnum;
double balance;

BankAccount::BankAccount(const std::string &client, const std::string &num, double bal) : // overloaded constructor
        name(client), acctnum(num), balance(bal) {}

void
BankAccount::show(void) const { // invoice display
    cout << "\nName: " << this->name << " , account number: " << this->acctnum << ", balance: " << this->balance
         << "$\n";
}

void
BankAccount::deposit(double cash) { // refill
    this->balance += cash;
}

void
BankAccount::withdraw(double cash) { // withdrawals
    this->balance >= cash ? this->balance -= cash : this->balance = 0;
}