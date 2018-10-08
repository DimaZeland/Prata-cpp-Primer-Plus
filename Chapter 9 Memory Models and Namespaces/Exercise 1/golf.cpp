#include "golf.h"

extern const int Len;

void setgolf(golf & g, const char * name, int hc) {
	strcpy_s(g.fullname,name);
	g.handicap = hc;
}

int setgolf(golf & g) {
	std::cout << "Please enter user name: ";
	std::cin >> g.fullname;
	std::cout << "Please enter user handicap: ";
	std::cin >> g.handicap;
	if (' ' == g.fullname[0] || '\0' == g.fullname[0])
		return 0;
	else
		return 1;
}

void handicap(golf & g, int hc) {
	g.handicap = hc;
}

void showgolf(const golf & g) {
	std::cout << "\nuser.fullname = " << g.fullname << ", user.handicap = " << g.handicap << ".\n";
}