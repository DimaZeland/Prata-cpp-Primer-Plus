#pragma once

#include <iostream>

class Golf {
private:
    static const int Len = 40;
    int itsHandicap;
public:
    char fullname[Len];

    inline int GetLen() { return Len; }

    void setgolf(const char *name, int hc);

    int setgolf();

    void handicap(int hc);

    void showgolf();
};