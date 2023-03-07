#include "winec.h"

Wine::Wine() // explicit overload constructor
	:std::string(" "), itsMyYears(0), Pair(1) { // initialization of inherited classes
	Pair::MyCollectionYear[0] = Pair::MyNumberBottles[0] = 0; // assigning member member values of the class Pair
}

Wine::Wine(const char * l, int y, const int yr[], const int bot[]) // overload constructor
	: std::string(l), itsMyYears(y), Pair(y) { // initialization of inherited classes
	for (int i = 0; i < y; ++i) { // assigning member member values of the class Pair
		Pair::MyCollectionYear[i] = yr[i];
		Pair::MyNumberBottles[i] = bot[i];
	}
}

Wine::Wine(const char * l, int y) // overload constructor
	:std::string(l), itsMyYears(y), Pair(y) { // initialization of inherited classes
	for (int i = 0; i < y; ++i) // assigning member member values of the class Pair
		Pair::MyCollectionYear[i] = Pair::MyNumberBottles[i] = 0;
}

void
Wine::GetBottles() { // input for year, bottle count
	for (int i = 0; i < itsMyYears; ++i) {
		std::cout << '\n' << i + 1 << " element:\nPlease enter crop year: ";
		int buf = 0;
		std::cin >> buf;
		Pair::MyCollectionYear[i] = buf;
		std::cout << "\nPlease enter the number of bottles: ";
		std::cin >> buf;
		Pair::MyNumberBottles[i] = buf;
	}
}

void
Wine::Show() {
	std::cout << "\nWine brand " << (std::string) *this << " has " << itsMyYears << " years of harvest:\n";
	for (int i = 0; i < itsMyYears; ++i)
		std::cout << Pair::MyCollectionYear[i] << " year: " << Pair::MyNumberBottles[i] << " bootles\n";
}