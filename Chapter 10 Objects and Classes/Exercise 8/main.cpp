#include "List.h"

int main()
{
	Object first;
	List Arr;

	cout << "\nEnter the name of new object: ";
	cin >> first.name;
	cout << "\nEnter the years of new object: ";
	cin >> first.years;
	Arr.Push(first);
	Arr.IsEmpty() ? std::cout << "\nThe list is empty\n" : std::cout << "\nThe list isn't empty\n";
	std::cout << "\nEnter index of list item\n";
	int ind = 0;
	cin >> ind;
	Arr.EditingElement(ind);


	system("pause");
	return 0;
}
