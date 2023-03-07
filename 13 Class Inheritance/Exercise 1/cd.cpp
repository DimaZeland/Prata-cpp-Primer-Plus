#include<iostream>
#include<string>
#include "cd.h"

Cd::Cd(const char * s1, const char * s2, int n, double x) : selections(n), playtime(x) { // overload constructor
	strcpy(performers, s1);
	strcpy(label, s2);
}

Cd::Cd(const Cd & d) : selections(d.selections), playtime(d.playtime) { // explicit copy constructor
	strcpy(performers, d.performers);
	strcpy(label, d.label);
}

Cd::Cd() : selections(0), playtime(0) { // explicit default constructor
	performers[0] = '\0';
	label[0] = '\0';
}

void
Cd::Report() const { // reports all CD data
	std::cout << "\nperformers: " << performers << ", label: " << label << ", selections: " << selections << ", playtime: " << playtime << std::endl;
}

Cd & Cd::operator=(const Cd & d) { // overloaded assignment operator
	if (this == &d)
		return *this;
	selections = d.selections;
	playtime = d.playtime;
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	return *this;
}