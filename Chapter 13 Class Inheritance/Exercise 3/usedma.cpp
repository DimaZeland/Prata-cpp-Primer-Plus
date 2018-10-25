// usedma.cpp -- inheritance, friends, and DMA
// compile with dma.cpp
#include <iostream>
#include "dma.h"
int main()
{
	using std::cout;
	using std::endl;
	using std::cin;

	AbstractDMA* pArr[4];
	int choise = 0;
	char Label[30]{ " " };
	int Ratings = 0;
	int Score = 0;
	char Color[30]{ " " };
	char Style[30]{ " " };
	for (int i = 0; i < 4; ++i) {
		cout << "\nObject #" << i + 1 << endl;
		cout << "\nEnter the type of the object <1 - baseDMA, 2 - lacksDMA, 3 - hasDMA>: ";
		std::cin >> choise;
		cout << "\nEnter the label: ";
		cin >> Label;
		cout << "\nEnter the Ratings: ";
		cin >> Ratings;
		switch (choise) {
		case 1: {
			cout << "\nEnter the score: ";
			cin >> Score;
			pArr[i] = new baseDMA(Label, Ratings, Score);
			break;
		}
		case 2: {
			cout << "\nEnter the Color: ";
			cin >> Color;
			pArr[i] = new lacksDMA(Color, Label, Ratings);
			break;
		}
		case 3: {
			cout << "\nEnter the Style: ";
			cin >> Style;
			pArr[i] = new hasDMA(Style, Label, Ratings);
			break;
		}
		default: {
			cout << "\nWrong choise(\n";
			pArr[i] = new baseDMA;
			break;
		}
		}
	}
	for (int i = 0; i < 4; ++i) {
		cout << "\nObject #" << i + 1 << endl;
		pArr[i]->View();
	}
	
	system("pause");
	return 0;
}
