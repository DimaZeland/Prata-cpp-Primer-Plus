#include "SALES.h"

void SALES::setSales(Sales & s, const double ar[], int n) {
	// gathers sales for 4 quarters interactively, stores them
	// in the sales member of s and computes and stores the
	// average, maximum, and minimum values
	int i = 0;
	s.max = *(ar + i);
	s.min = *(ar + i);
	s.sales[i] = *(ar + i);
	s.average = 0;
	s.average += *(ar + i);
	for (++i; i < SALES::QUARTERS; ++i) {
		s.sales[i] = *(ar + i);
		if (*(ar + i) > s.max)
			s.max = *(ar + i);
		if (*(ar + i) < s.min)
			s.min = *(ar + i);
		s.average += *(ar + i);
	}
	s.average /= SALES::QUARTERS;
}

void SALES::setSales(Sales & s) {
	int i = 0;
	s.max = s.sales[i];
	s.min = s.sales[i];
	s.average += s.sales[i];
	for (++i; i < SALES::QUARTERS; ++i) {
		if (s.sales[i-1] > s.max)
			s.max = s.sales[i];
		if (s.sales[i-1] < s.min)
			s.min = s.sales[i-1];
		s.average += s.sales[i-1];
	}
	s.average /= SALES::QUARTERS;
}

// display all information in structure s
void SALES::showSales(const Sales & s) {
	for (int i = 0; i < SALES::QUARTERS; ++i)
		std::cout << i << " s.sales = " << s.sales[i] << '\n';
	std::cout << "\ns.average = " << s.average <<
		"\ns.max = " << s.max <<
		"\ns.min = " << s.min << '\n';
}