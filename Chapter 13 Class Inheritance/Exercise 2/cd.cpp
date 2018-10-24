#include<iostream>
#include<string>
#include "cd.h"

Cd::Cd(const char * s1, const char * s2, int n, double x) : selections(n), playtime(x) { // overload constructor
	int len1 = strlen(s1), len2 = strlen(s2);
	performers = new char[len1 + 1], label = new char[len2 + 1];
	strcpy(performers, s1);
	strcpy(label, s2);
}

Cd::Cd(const Cd & s) : selections(s.selections), playtime(s.playtime) { // explicit copy constructor
	int len1 = strlen(s.performers), len2 = strlen(s.label);
	performers = new char[len1 + 1], label = new char[len2 + 1];
	strcpy(performers, s.performers);
	strcpy(label, s.label);
}

Cd::Cd() : selections(0), playtime(0) { // explicit default constructor
	performers = label = nullptr;
}

Cd::~Cd() { // explicit virtual destructor for the base class
	delete[] performers, delete[] label;
	performers = label = nullptr;
}

void
Cd::Report() const { // reports all CD data
	std::cout << "\nperformers: ";
	if (performers) // if nullptr != performers 
		std::cout << performers;
	else
		std::cout << " no name";
	std::cout << ", label: ";
	if (label) // if nullptr != label 
		std::cout << label;
	else
		std::cout << " no name";
	std::cout << ", selections: " << selections << ", playtime: " << playtime << std::endl;
}

Cd & Cd::operator=(const Cd & s) { // overloaded assignment operator
	if (this == &s)
		return *this;
	delete[] performers, delete[] label;
	int len1 = strlen(s.performers), len2 = strlen(s.label);
	performers = new char[len1 + 1], label = new char[len2 + 1];
	strcpy(performers, s.performers);
	strcpy(label, s.label);
	return *this;
}