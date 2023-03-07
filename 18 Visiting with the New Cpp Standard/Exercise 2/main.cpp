#include<iostream>
#include<utility>
#include"Cpmv.h"

int main(){

	cout << "\nCpmv first;\n";
	Cpmv first; // default constructor()
	cout << "\nfirst.Display();\n";
	first.Display();

	cout << "\nstd::string str1 = \"string1\", str2 = \"string2\";\n" <<
		"Cpmv second(str1, str2);\n";
	std::string str1 = "string1", str2 = "string2";
	Cpmv second(str1, str2); // constructor (std::string, std::string);
	cout << "\nsecond.Display(); \n";
	second.Display();

	cout << "\nCpmv third(second);\n";
	Cpmv third(second); // overload copy-constructor
	cout << "\nthird.Display();\n";
	third.Display();

	cout << "\nCpmv four(std::move(second));\n";
	Cpmv four(std::move(second)); // use transfer copy-constructor (Cpmv&&)
	cout << "\nfour.Display();\n";
	four.Display();

	cout << "\ninfo about object second after using \"four(std::move(second))\":\n" << "second.Display();\n";
	second.Display();

	cout << "\nfirst = four;\n";
	first = four;
	cout << "\nfirst.Display();\n";
	first.Display();

	cout << "\nsecond = std::move(third);\n";
	second = std::move(third);
	cout << "\nInfo about second object after second = std::move(third):\n" << "second.Display();\n";
	second.Display();
	cout << "\nInfo about third object after second = std::move(third):\n" << "third.Display();\n";
	third.Display();

	std::cout << "\nthird = first + second;\n";
	third = first + second; // use Cpmv::operator(const& Cpmv&)
	std::cout << "\nthird.Display()\n";
	third.Display();

	system("pause");
	return 0;
}