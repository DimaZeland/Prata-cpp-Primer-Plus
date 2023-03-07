// stack.cpp -- Stack member functions
#include "stack.h"
Stack::Stack(int n) : size(n), top(0)    // create an empty stack
{
	if (size) // if the number of elements is greater than zero
		pitems = new Item[n];
	else
		pitems = nullptr;
}

Stack::Stack(const Stack & st) : size(st.size), top(st.top) { // overloaded deep copy constructor
	if (size) { // if the number of elements is greater than zero
		pitems = new Item[size];
		for (int i = 0; i < size; ++i)
			pitems[i] = st.pitems[i];
	}
	else
		pitems = nullptr;
}

Stack::~Stack() { // destructor
	delete[]pitems;
	pitems = nullptr;
}

bool Stack::isempty() const
{
	return top == 0;
}

bool Stack::isfull() const
{
	return top == MAX;
}

bool Stack::push(const Item & item)
{
	if (top < MAX)
	{
		pitems[top++] = item;
		return true;
	}
	else
		return false;
}

bool Stack::pop(Item & item)
{
	if (top > 0)
	{
		item = pitems[--top];
		return true;
	}
	else
		return false;
}

Stack & Stack::operator=(const Stack & st) {
	if (this == &st)
		return *this;
	delete[] pitems;
	size = st.size;
	top = st.top;
	if (size) { // if the number of elements is greater than zero
		pitems = new Item[size];
		for (int i = 0; i < size; ++i)
			pitems[i] = st.pitems[i];
	}
	else
		pitems = nullptr;
	return *this;
}
