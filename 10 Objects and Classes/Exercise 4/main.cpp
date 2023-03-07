#include "SALES.h"

int main() {

	SALES::Sales one;
	double Arr[SALES::Sales::QUARTERS] = { 110,111,112,113 };
	SALES::Sales two(Arr, SALES::Sales::QUARTERS);
	one.showSales();
	two.showSales();
	system("pause");
	return 0;
}
