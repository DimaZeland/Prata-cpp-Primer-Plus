#pragma once

#include <cstring>
#include <iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;

class BankAccount
{
private:
	std::string name;
	std::string acctnum;
	double balance;
public:
	BankAccount(const std::string & client, const std::string & num, double bal = 0.0); // overloaded constructor
	~BankAccount() {}
	void show(void) const; // invoice display
	void deposit(double cash); // refill
	void withdraw(double cash); // withdrawals
};