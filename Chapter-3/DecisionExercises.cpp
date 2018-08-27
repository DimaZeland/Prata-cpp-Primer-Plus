//Stephen Prata
//"C++ Primer Plus"
//Sixth Edition

//Chapter 3. Working with data

//Programming exercises

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

class MyClass {
public:
	MyClass() {}
	~MyClass() {}
	void Avto()const;
	void AvtoEU()const;
	void BodyMassIndex()const;
	void Converter()const;
	void Locate()const;
	void Population()const;
	void TimeConverter()const;

};

void
MyClass::Avto()const {
	short miles{ 0 }, gallons{ 0 };
	cout << "Enter the number of miles: ";
	cin >> miles;
	cout << "Enter the number of gallons of gasoline consumed: ";
	cin >> gallons;
	cout << "Flow rate " << float(gallons) / miles << " gal/mil\n";
}

void
MyClass::AvtoEU()const {
	float eu_style{ 0 };
	constexpr float miles_per_100km = 62.14, litr_per_gallon = 3.875;
	cout << "Enter the petrol consumption in liters per 100 km: ";
	cin >> eu_style;
	cout << "Flow rate (US): " << litr_per_gallon * miles_per_100km / eu_style << " mil/gal\n";
}

void
MyClass::BodyMassIndex()const {
	double height{ 0.0 }, weight{ 0.0 };
	cout << "Enter the height in feet:_\b";
	cin >> height;
	cout << "Enter weight in pounds:__\b\b";
	cin >> weight;
	cout << "BMI = " << (weight / 2.2) / std::pow(height * 12 * 0.0254, 2) << endl;
}

void
MyClass::Converter()const {
	cout << "Enter the inches:___\b\b\b";
	double d{ 0 };
	cin >> d;
	const double f_koef{ 5.0 / 12.0 };
	cout << d << " inches = " << d * f_koef << " ft\n";
}

void
MyClass::Locate()const {
	short degrees{ 0 }, minutes{ 0 }, seconds{ 0 };
	cout << "Enter a latitude in degrees, minutes, and seconds\nFirst, enter the degrees:__\b\b";
	cin >> degrees;
	cout << "Next, enter the minutes of arc:__\b\b";
	cin >> minutes;
	cout << "finally, enter the seconds of arc:__\b\b";
	cin >> seconds;
	cout << degrees << " degrees, " << minutes << ", " << seconds << " seconds = " << float(degrees + ((minutes + seconds / 60.0) / 60.0)) << " degrees\n";
}

void
MyClass::Population()const {
	long long usa{ 0 }, world{ 0 };
	float percent{ 0.0 };
	cout << "Enter the world's population: ";
	cin >> world;
	cout << "Enter the population of the US: ";
	cin >> usa;
	cout << "The population of the US is " << float(usa / (world / 100.0)) << "% of the world population.\n";
}

void
MyClass::TimeConverter()const {
	int void_seconds{ 0 }, days{ 0 }, hours{ 0 }, minutes{ 0 }, seconds{ 0 };
	const int Days{ 24 * 60 * 60 }, Hours{ 60 * 60 }, Minutes{ 60 }, Seconds{ 1 };
	cout << "Enter the number of seconds: ";
	cin >> void_seconds;
	days = void_seconds / Days;
	hours = (void_seconds - days * Days) / Hours;
	minutes = (void_seconds - days * Days - hours * Hours) / Minutes;
	seconds = (void_seconds - days * Days - hours * Hours - minutes * Minutes) / Seconds;
	cout << void_seconds << " seconds = " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds\n";
}

int main() {
	
	using namespace std;

	auto* pObj = new MyClass;

	//Task 1
	pObj->Converter();
	//Task 2
	pObj->BodyMassIndex();
	//Task 3
	pObj->Locate();
	//Task 4
	pObj->TimeConverter();
	//Task 5
	pObj->Population();
	//Task 6
	pObj->Avto();
	//Task 7
	pObj->AvtoEU();

	delete pObj;
	pObj = 0;

	system("pause");
	return 0;
}
