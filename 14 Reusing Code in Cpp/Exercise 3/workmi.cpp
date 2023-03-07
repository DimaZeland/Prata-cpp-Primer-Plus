// workmi.cpp -- multiple inheritance
// compile with workermi.cpp
#include <iostream>
#include <cstring>
#include "workermi.h"
#include "queue.h"

const int SIZE = 5;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;

	QueueTp<Worker *> q;
	Worker * pw;
	
	Worker * lolas[SIZE];

	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the employee category:\n"
			<< "w: waiter  s: singer  "
			<< "t: singing waiter  q: quit\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "Please enter a w, s, t, or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'w':   pw = new Waiter;
			break;
		case 's':   pw = new Singer;
			break;
		case 't':   pw = new SingingWaiter;
			break;
		default: pw = new Waiter;
			break;
		}
		cin.get();
		pw->Set();
		q.enqueue(pw);
	}

	cout << "\nHere is your staff:\n";
	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		q.dequeue(pw);
		pw->Show();
		delete pw;
	}
	cout << "Bye.\n";
	 cin.get();
	 cin.get();
	return 0;
}
