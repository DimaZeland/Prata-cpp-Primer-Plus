// stone.cpp -- user-defined conversions
// compile with stonewt.cpp
#include <iostream>
using std::cout;
#include "stonewt.h"
void display(Stonewt & st, int n);
int main()
{
	Stonewt incognito = (275, Stonewt::STOUN); // uses constructor to initialize
	Stonewt wolfe(285.7, Stonewt::POUND);    // same as Stonewt wolfe = 285.7;
	Stonewt taft(21, 8, Stonewt::STOUNPOUNDS);

	Stonewt Arr[6]{ 160,170,180 };

	Stonewt Min = Arr[0];
	Stonewt Max = Arr[0];
	Stonewt Etalon(11, 0, Stonewt::STOUN);
	int scores = 0;
	cout << Arr[0];
	for (int i = 1; i < 6; ++i) {
		cout << Arr[i];
		if (Arr[i] < Min)
			Min = Arr[i];
		if (Arr[i] > Max)
			Max = Arr[i];
		if (Arr[i] > Etalon)
			scores++;
	}
	cout << "\nMax element: " << Max << ", min element " << Min << ", " << scores << " elements are more than 11 pounds\n"; 
	system("pause");
	return 0;
}

void display(Stonewt & st, int n){
	for (int i = 0; i < n; i++){
		cout << "Wow! ";
		cout << st << '\n';
	}
}
