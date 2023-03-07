#include "winec.h"


Wine::Wine() // explicit overload constructor
	:itsMyName(" "), itsMyYears(0), itsMyData(1) { // initialization of member data
	itsMyData.MyCollectionYear[0] = itsMyData.MyNumberBottles[0] = 0; // assigning member member values ItsMyData
}

Wine::Wine(const char * l, int y, const int yr[], const int bot[]) // overload constructor
	: itsMyName(l), itsMyYears(y), itsMyData(y) { // initialization of member data
	for (int i = 0; i < y; ++i) { // assigning member member values ItsMyData
		itsMyData.MyCollectionYear[i] = yr[i];
		itsMyData.MyNumberBottles[i] = bot[i];
	}
}

Wine::Wine(const char * l, int y) // overload constructor
	:itsMyName(l), itsMyYears(y), itsMyData(y) { // initialization of member data
	for (int i = 0; i < y; ++i) // assigning member member values ItsMyData
		itsMyData.MyCollectionYear[i] = itsMyData.MyNumberBottles[i] = 0;
}

void
Wine::GetBottles() { // input for year, bottle count
	for (int i = 0; i < itsMyYears; ++i) {
		std::cout << '\n' << i + 1 << " element:\nPlease enter crop year: ";
		int buf = 0;
		std::cin >> buf;
		itsMyData.MyCollectionYear[i] = buf;
		std::cout << "\nPlease enter the number of bottles: ";
		std::cin >> buf;
		itsMyData.MyNumberBottles[i] = buf;
	}
}

void
Wine::Show() {
	std::cout << "\nWine brand " << itsMyName << " has " << itsMyYears << " years of harvest:\n";
	for (int i = 0; i < itsMyYears; ++i)
		std::cout << itsMyData.MyCollectionYear[i] << " year: " << itsMyData.MyNumberBottles[i] << " bootles\n";
}