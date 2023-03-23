#pragma once

#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;

struct Object {
    Object() : name(" "), years(0) {}

    std::string name;
    int years;
};

class List {
private:
    const static int size = 20;
    Object pArr[size];
    int index;
public:
    List() : index(0) {}

    ~List() {}

    bool Push(Object &); // add item to end of list
    bool IsEmpty() const;

    bool IsFull() const;

    void EditingElement(int index); // edit item data
};