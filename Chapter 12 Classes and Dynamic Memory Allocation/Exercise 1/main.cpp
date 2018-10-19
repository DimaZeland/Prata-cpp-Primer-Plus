#include <iostream>
#include "cow.h" // to avoid confusion with complex.h

int main(){
	Cow one, two("Daffy", "Forex", 100), three(two);
	std::cout << "\none info:" << one << "\ntwo info:" << two << "\nthree info:" << three << std::endl;
	one = two;
	std::cout << "\none info:" << one << "\ntwo info:" << two << std::endl;
	system("pause");
	return 0;
}