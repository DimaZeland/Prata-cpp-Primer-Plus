// workmi.cpp -- multiple inheritance
// compile with workermi.cpp
#include <iostream>
#include <cstring>
#include<ctime>
#include "Person.h"

const int SIZE = 5;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;

	Person* lolas[SIZE];

	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the Person category:\n"
			<< "p: Person  g: Gunslinger  "
			<< "l: PokerPlayer b: BadDude  q: quit\n";
		cin >> choice;
		while (strchr("pglbq", choice) == NULL)
		{
			cout << "Please enter p, g, l, b, or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'p':   lolas[ct] = new Person;
			break;
		case 'g':   lolas[ct] = new Gunslinger;
			break;
		case 'l':   lolas[ct] = new PokerPlayer;
			break;
		case 'b':   lolas[ct] = new BadDude;
			break;
		default:   lolas[ct] = new Person;
			break;
		}
		cin.get();
		lolas[ct]->Set();
	}

	cout << "\nHere is your staff:\n";
	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		lolas[i]->Show();
	}
	for (i = 0; i < ct; i++)
		delete lolas[i];
	cout << "Bye.\n";
	 cin.get();
	 cin.get();
	return 0;
}