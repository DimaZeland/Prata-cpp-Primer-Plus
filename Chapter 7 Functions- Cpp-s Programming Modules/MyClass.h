#pragma once

#include<algorithm>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct box {
public:
	box() : maker{ "maker" }, height(10.2), wight(5.1), lenght(4.4), volume(11.0) {}
	char maker[40];
	float height;
	float wight;
	float lenght;
	float volume;
};

class MyClass
{
public:
	MyClass() : itsGolfResult{}, itsArr{} {}
	~MyClass() {}
	// class methods
	void DisplayResults(void)const; // display the results of golf games
	void DisplayBox(const box); // display members of the structure
	void DisplayBoxMenu(MyClass&, box&); // functionality of work with structure
	void FactorialMenu(void)const;  //derivation of the factorial of given numbers
	void Fill_array(double*, int = size); // array filling
	double FindMeanValue()const; // Find the mean value array's itsGolfResult elements
	inline double GetAverageHarmonic(double* number1, double* number2)const { // return the average harmonic of two numbers
		return 2.0 * (*number1) * (*number2) / ((*number1) + (*number2));}
	int GetFactorial(int)const; // derivation the factorial of given numbers
	long double	Probability(unsigned, unsigned, unsigned); // taking into account the chance of winning in the American lottery
	void Reserve_array(double*, int = size); // changing the order of array elements
	void SetitsGolfResult(void); // set the results of 10 golf games
	inline void SetBoxVolume(box& one) { one.volume = one.height * one.wight * one.lenght; } // reset the value of structure's memeber "volume"
	void Show_array(double*, int = size); // deducing the values of array elements
	static const int size = 10;
	double itsArr[size];
	double calculate(double, double, double(MyClass::*pFunc)(double, double)); // Task 10
	double Sum(double, double); // return the sum of two numbers
	double Multiplication(double, double); // return the multiplication of two numbers
private:
	double itsGolfResult[10]; // include the results of 10 golf games
};
