#pragma once

#ifndef CLASSIC_H_
#define CLASSIC_H_

#include "cd.h"

class Classic : public Cd {
private:
    char *mySongName; // main song name
public:
    Classic(); // explicit base constructor
    Classic(const char *, const char *, const char *, int, double); // overload constructor
    Classic(const Classic &); // explicit copy constructor
    ~Classic(); // explicit base destructor
    Classic &operator=(const Classic &d); // overloaded assignment operator
    virtual void Report() const; // reports all CD data
};

#endif
