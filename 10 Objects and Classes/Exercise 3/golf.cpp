#include "golf.h"

void
Golf::setgolf(const char *name, int hc) {
    strcpy_s(fullname, name);
    itsHandicap = hc;
}

int
Golf::setgolf() {
    std::cout << "Please enter user name: ";
    std::cin >> fullname;
    std::cout << "Please enter user handicap: ";
    std::cin >> itsHandicap;
    if (' ' == fullname[0] || '\0' == fullname[0])
        return 0;
    else
        return 1;
}

void
Golf::handicap(int hc) {
    itsHandicap = hc;
}

void
Golf::showgolf() {
    std::cout << "\nuser.fullname = " << fullname << ", user.handicap = " << itsHandicap << ".\n";
}