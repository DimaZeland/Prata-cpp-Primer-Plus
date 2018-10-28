#pragma once
#include <iostream>
#include<string>
#include<valarray>

typedef std::valarray<int> ArrayInt;
//typedef Pair<ArrayInt, ArrayInt> PairArray;

struct Pair {
public:
	// member data
	ArrayInt MyCollectionYear;
	ArrayInt MyNumberBottles;
	// overload base constructor
	Pair(int years = 0)
	:MyCollectionYear(years), MyNumberBottles(years) {}
};

class Wine{
private:
	// member data
	std::string itsMyName;
	int itsMyYears;
	Pair itsMyData;
public:
	// constructors & destructor
	Wine(); // explicit overload constructor
	Wine(const char * l, int y, const int yr[], const int bot[]); // overload constructor
	Wine(const char * l, int y); // overload constructor
	~Wine(){}
	// class methods
	void GetBottles();
	inline const std::string&   Label() { return itsMyName; } // return the name of the wine
	inline int sum() const { return itsMyData.MyNumberBottles.sum(); } // return of the total number of bottles
	void Show();
};