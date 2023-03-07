#include "List.h"

bool
List::Push(Object& obj) { // add item to end of list
	if (index < size) {
		this->pArr[index].name = obj.name;
		this->pArr[index].years = obj.years;
		++index;
		return true;
	}
	else {
		if (index > size)
			index = size;
		return false;
	}
}

bool
List::IsEmpty()const {
	bool res = false;
	!index ? res = true : res = false;
	return res;
}

bool
List::IsFull()const {
	bool res = false;
	size == index ? res = true : res = false;
	return res;
}

void
List::EditingElement(int index) { // edit item data
	if (index > size or index < 0) {
		cout << "\nThe index entered is outside the list of items!\n";
		return;
	}
	else {
		cout << "Old name: " << this->pArr[index].name << ", old years: " << this->pArr[index].years << '\n';
		cout << "\nEnter new name for the " << index + 1 << " element: ";
		cin >> this->pArr[index].name;
		cout << "\nEnter new value of years for the " << index + 1 << " element: ";
		cin >> this->pArr[index].years;
	}
}