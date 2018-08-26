#pragma once

#include <iostream>
#include<array>
#include<string>
#include<vector>
#include <stdlib.h>
#include<ctime>
#include<iomanip>

using std::cout;
using std::cin;
using std::endl;

class MyClass {
public:
	//constructor & destructor
	MyClass() {}
	~MyClass() {}

	// class methods
	void BookSales(void)const; // one year book Sales Accounting
	void BookSales3Years(void)const; // three year book Sales Accounting
	void CalculationBalance(float, float)const; // calculation of the Balance Sheet
	void CarCatalog()const;  // displaying information about the car catalog
	void CountingSumNumbers(void)const; // counting the sum of the entered numbers
	void DispayingStars(int&)const; // displaying entered number of stars
	void ReturnFactorial(void)const; // return of the factorial number
	void ReadingWords(void)const; // counting the number of entered words
	void ReadingWordsS(void)const; // counting the number of entered words (using std::string)
	int Sum2Number(int &, int&)const; // return the sum of a range of two numbers
	struct Car
	{
	public:
		// constructor & destructor
		Car() : manufacturer(" "), yearRelease(0) {}
		Car(std::string& Manufactured, int& YearsRelease) : manufacturer(Manufactured), yearRelease(YearsRelease) {} // overloaded constructor
		Car(const Car& rhs) : manufacturer(rhs.manufacturer), yearRelease(rhs.yearRelease) {} // overload copy-constructor
		// structure data
		std::string manufacturer;
		int yearRelease;
	};
private:
};





