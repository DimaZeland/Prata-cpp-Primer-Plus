// randwalk.cpp -- using the Vector class
// compile with the vect.cpp file
#include <iostream>
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype
#include<fstream>
#include "vect.h"
int main()
{
	using namespace std;
	std::ofstream fout;
	fout.open("thewalk.txt");
	using VECTOR::Vector;
	srand(time(0));     // seed random-number generator
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	int attempt = 0;
	double maxStep = 0, minStep = DBL_MAX, averageStep = 0, stepSize = 1;
	cout << "Enter number of attempts: ";
	cin >> attempt;
	cout << "Enter target distance (q to quit): ";
	cin >> target;
	cout << "Enter step length: ";
	cin >> dstep;
	fout << "Target Distance: " << target << ". Step Size: " << dstep << ", number of attempts: " << attempt <<"\n";

	for (int i = 0; i < attempt; ++i){ // busting n attempts
		while (result.magval() < target){
			direction = rand() % 360;
			step.reset(dstep, direction, VECTOR::Vector::Mode::POL);
			result = result + step;
			//fout << steps << ": " << result << '\n';
			steps++;
		}
		if (steps > maxStep)
			maxStep = steps;
		if (steps < minStep)
			minStep = steps;
		averageStep += steps;
		steps = 0;
		++stepSize;
		result.reset(0.0, 0.0);
	}
	averageStep /= stepSize;
	fout << "\nMax Step: " << maxStep << ", Min Step: " << minStep << ", average Step: " << averageStep << "\n";
	cout << "Bye!\n";
	system("pause");
	return 0;
}
