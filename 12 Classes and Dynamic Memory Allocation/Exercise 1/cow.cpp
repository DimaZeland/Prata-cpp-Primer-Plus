#include <iostream>
#include <cstring>
#include "cow.h"

Cow::Cow() : name("\0"), hobby(nullptr), weight(0) { // overloaded default constructor
}

Cow::Cow(const char * nm, const char * ho, double wt) : weight(wt) { // constructor with formal parameters
	int i = 0;
	for (; i < 19 and '\0' != *(nm + i); ++i) // character copying
		name[i] = *(nm + i);
	name[i] = '\0'; // line terminator

	int len = std::strlen(ho);
	hobby = new char[len + 1]; // allocation of dynamic memory for the member "char* hobby"
	strcpy_s(hobby, len+1, ho);

}

Cow::Cow(const Cow & c) : weight(c.weight) { // overloaded deep copy copier
	strcpy_s(name, c.name);
	int len = std::strlen(c.hobby);
	hobby = new char[len + 1]; // allocation of dynamic memory for the member "char* hobby"
	strcpy_s(hobby, len+1, c.hobby);
}

Cow::~Cow() {
	delete[] hobby; // releasing dynamic memory of the member "char* hobby"
	hobby = nullptr;
}

Cow & Cow::operator=(const Cow & c) {
	if (this == &c) // assigning an object to yourself
		return *this;
	delete[] hobby; // release old line
	strcpy_s(name, c.name);
	int len = std::strlen(c.hobby);
	hobby = new char[len + 1]; // allocation of dynamic memory for the member "char* hobby"
	strcpy_s(hobby, len+1, c.hobby);
	weight = c.weight;
	return *this;
}

void Cow::ShowCow() const { // display all cow data
	std::cout << "\nName: " << name << ", hobby: " << hobby << ", weight: " << weight << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Cow& c) { // overloaded output statement
	if (c.hobby) // if the pointer is not reset
	os << "\nName: " << c.name << ", hobby: " << c.hobby << ", weight: " << c.weight << std::endl;
	else
		os << "\nName: " << c.name << ", no hobby, weight: " << c.weight << std::endl;
	return os;
}