#pragma once
#include <iostream>
#include<string>
#include<valarray>

typedef std::valarray<int> ArrayInt;
//typedef Pair<ArrayInt, ArrayInt> PairArray;
//PairArray::operator=(PairArray(ArrayInt(), ArrayInt()));

class Pair {
public:
	// member data
	ArrayInt MyCollectionYear;
	ArrayInt MyNumberBottles;
	// overload base constructor
	Pair(int years = 0)
	:MyCollectionYear(years), MyNumberBottles(years) {}
};

class Wine: private std::string, private Pair{
private:
	// member data
	int itsMyYears;
public:
	// constructors & destructor
	Wine(); // explicit overload constructor
	Wine(const char * l, int y, const int yr[], const int bot[]); // overload constructor
	Wine(const char * l, int y); // overload constructor
	~Wine(){}
	// class methods
	void GetBottles();
	inline std::string   Label() { return (std::string) *this; } // return the name of the wine
	inline int sum() const {
		return Pair::MyNumberBottles.sum();
	}
	void Show();
};