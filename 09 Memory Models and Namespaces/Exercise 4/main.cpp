#include "SALES.h"

int main(){
	
	SALES::Sales one, two;
	two = { 110,111,112,113};
	double Arr[SALES::QUARTERS] = { 110, 225,114,254 };
	SALES::setSales(one, Arr, SALES::QUARTERS);
	SALES::showSales(one);
	SALES::setSales(two);
	SALES::showSales(two);
	system("pause");
	return 0;
}
