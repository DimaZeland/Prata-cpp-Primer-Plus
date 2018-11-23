#include<iostream>

long double sum_values() { return 0; }

template<typename T, typename... Args>
long double sum_values(T value, Args... args) {
	long double sum = value;
	sum += sum_values(args...);
	return sum;
}


int main(){
	
	std::cout  << sum_values(1, 2, 3) << std::endl;
	std::cout << sum_values(1, 2, 3, 4) << std::endl;
	std::cout << sum_values(-1, -20, 3.5, 43.7) << std::endl;
	std::cout << sum_values(-1, -2, 3.5) << std::endl;



	system("pause");
	return 0;
}