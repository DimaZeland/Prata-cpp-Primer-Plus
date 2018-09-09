#pragma once

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
	MyClass() : itsGolfResult{} {}
	~MyClass() {}
	// class methods
	void DisplayResults(void)const; // display the results of golf games
	void DisplayBox(const box); // display members of the structure
	void DisplayBoxMenu(MyClass&, box&); // functionality of work with structure
	void FactorialMenu(void)const;  //derivation of the factorial of given numbers
	double FindMeanValue()const; // Find the mean value array's itsGolfResult elements
	inline double GetAverageHarmonic(double* number1, double* number2)const { // return the average harmonic of two numbers
		return 2.0 * (*number1) * (*number2) / ((*number1) + (*number2));}
	int GetFactorial(int)const; // derivation the factorial of given numbers
	long double	Probability(unsigned, unsigned, unsigned); // taking into account the chance of winning in the American lottery
	void SetitsGolfResult(void); // set the results of 10 golf games
	inline void SetBoxVolume(box& one) { one.volume = one.height * one.wight * one.lenght; } // reset the value of structure's memeber "volume"
private:
	double itsGolfResult[10]; // include the results of 10 golf games
};