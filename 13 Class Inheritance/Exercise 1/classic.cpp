#include "classic.h"
#include<iostream>
#include<string>

Classic::Classic() :Cd() { // explicit base constructor
	mySongName = nullptr;
}

Classic::Classic(const char* song, const char * s1, const char * s2, int n, double x) : Cd(s1, s2, n, x) { // overload constructor
	int len = strlen(song);
	mySongName = new char[len + 1];
	strcpy(mySongName, song);
}

Classic::Classic(const Classic & s) :Cd(s) { // explicit copy constructor
	int len = strlen(s.mySongName);
	mySongName = new char[len + 1];
	strcpy(mySongName, s.mySongName);
}

Classic::~Classic() { // explicit base destructor
	delete[] mySongName;
	mySongName = nullptr;
}

Classic & Classic::operator=(const Classic & d) { // overloaded assignment operator
	if (this == &d)
		return *this;
	Cd::operator=(d); // copying the base part
	delete[] mySongName; // preparation for surgery new for mySongName
	int len = strlen(d.mySongName);
	mySongName = new char[len + 1];
	strcpy(mySongName, d.mySongName);
	return *this;
}

void Classic::Report()const { // reports all CD data
	if (mySongName) { // if nullptr != mySongName 
		Cd::Report(); // base class data output
		std::cout << "mySongName: " << mySongName << std::endl;
	}
	else {
		Cd::Report(); // base class data output
		std::cout << "mySongName: no name\n";
	}
}