#include "Move.h"
#pragma once

//class Move
//{
//private:
//	double x;
//	double y;
//public:


Move::Move(double a, double b): x(a), y(b) {} // sets x, y to a, b
void
Move::showmove() const { // shows current x, y values
	cout << "\nx = " << x << ", y = " << y << '\n';
}
Move
Move::add(const Move & m) const {
	Move Object;
	Object.x = m.x;
	Object.y = m.y;
	return Object;
}
void
Move::reset(double a, double b){ // resets x,y to a, b
	x = a, y = b;
};