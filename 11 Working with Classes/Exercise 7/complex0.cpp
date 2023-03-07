#include <iostream>
using std::cout;
#include "complex0.h"

std::istream & operator>>(std::istream & os, complex & v) {
	cout << "real: ";
	if (!(std::cin >> v.myReal))
		return os;
	cout << "imaginary: ";
	std::cin >> v.myImaginary;
	return os;
}

std::ostream& operator<< (std::ostream & os, const complex & v){
	os << '(' << v.myReal << ", " << v.myImaginary << "i)";
	return os;
}

complex complex::operator+(complex& v){
	complex Sum;
	Sum.myReal = this->myReal + v.myReal;
	Sum.myImaginary = this->myImaginary + v.myImaginary;
	return Sum;
}

complex complex::operator-(complex& v) {
	complex Sub;
	Sub.myReal = this->myReal - v.myReal;
	Sub.myImaginary = this->myImaginary - v.myImaginary;
	return Sub;
}

complex complex::operator*(complex& v) {
	complex Mult;
	Mult.myReal = (this->myReal * v.myReal) - (this->myImaginary * v.myImaginary);
	Mult.myImaginary = (this->myReal * v.myImaginary) + (v.myReal *this->myImaginary);
	return Mult;
}

complex operator*(double n, complex& v) {
	complex Mult;
	Mult.myReal = n * v.myReal;
	Mult.myImaginary = n * v.myImaginary;
	return Mult;
}

complex& complex::operator~() {
	-myImaginary;
	return *this;
}