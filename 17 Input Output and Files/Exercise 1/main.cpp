#include <iostream>
#include<string>

int main(){
	std::cout << "Enter a string: ";
	int i = 0;
	while (std::cin.peek() != '$') {
		std::cin.get();
		++i;
	}
	char ch;
	std::cin.get(ch);
	std::cout << "\nNumber of characters: " << i << ", next character is " << ch << std::endl;

	system("pause");
	return 0;
}
