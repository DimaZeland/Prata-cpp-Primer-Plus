#pragma once

#include<array>
#include<cctype>
#include<fstream>
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>

using std::cout;
using std::cin;
using std::endl;

class MyClass
{
public:
	// constructor & destructor
	MyClass();
	~MyClass();
	// operator overloading
	void operator +=(const char&); // operator overload + = for string concatenation and symbol
	// class methods
	void AccountingDonations(void); // Accounting donations
	void ConclusionPatrons(void); // the conclusion of patrons of the society of protection of influential persons
	void ConclusionPatronsFile(void); // the conclusion of patrons of the society of protection of influential persons
	void DisplayBopMembers(); // Display information about the BOP members according to a given parameter
	void KeyboardInputConversions(void); // Keyboard Input Conversions
	void ReadingFile(void)const; // counting the number of characters in a file
	void ReadingWords(void)const; // Reading and sorting words
	void ShowsMenu(void); // prototype menu
	void TaxCalculate(void)const; // Calculate income tax in Neutron
private:
	std::string itsSentence; // string for saving text input from Exercise 1
	std::array<double, 10> itsDonations; // array of donations
	unsigned flag:1; // use bit fields to save memory
	struct bop {
		char fullname[30]; // real name
		char title[30]; // title
		char bopname[30]; // bop name
		int preference;
	};
	bop Arr[5]{};
	struct PatronInfo { // structure for entering information about a particular patron (Task 6)
		std::string name;
		double donations;
	};
	std::vector <PatronInfo> itsPatronsArr; // an array of data on patrons of the society protecting influential people
};

