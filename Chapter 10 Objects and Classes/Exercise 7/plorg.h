#pragma once

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

class Plorg
{
private:
	char Myname[19];
	int MyCI;
public:
	Plorg(const char*name = "Plorga", int consIndex = 50);
	void Show()const; //cout object data 
};