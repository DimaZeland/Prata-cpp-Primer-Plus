#include "SALES.h"

SALES::Sales::Sales(const double ar[], int n) {
	// gathers sales for 4 quarters interactively, stores them
	// in the sales member of s and computes and stores the
	// average, maximum, and minimum values
	int i = 0;
	max = *(ar + i);
	min = *(ar + i);
	sales[i] = *(ar + i);
	average = 0;
	average += *(ar + i);
	for (++i; i < SALES::Sales::QUARTERS; ++i) {
		sales[i] = *(ar + i);
		if (*(ar + i) > max)
			max = *(ar + i);
		if (*(ar + i) < min)
			min = *(ar + i);
		average += *(ar + i);
	}
	average /= SALES::Sales::QUARTERS;
}

SALES::
Sales::Sales() : max(0), min(0), average(0) {
	for (int i = 0; i < QUARTERS; ++i)
		sales[i] = 0;
}

// display all information in structure s
void SALES::
Sales::showSales()const {
	for (int i = 0; i < SALES::Sales::QUARTERS; ++i)
		std::cout << i << " s.sales = " << sales[i] << '\n';
	std::cout << "\ns.average = " << average <<
		"\ns.max = " << max <<
		"\ns.min = " << min << '\n';
}