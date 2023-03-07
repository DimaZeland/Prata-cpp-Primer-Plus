#include<iostream>
#include<string>
bool AnalyzePolindrom(std::string &); // return true if the argument is polindrom

int main() {
	std::string str = " ";
	std::cout << "Enter string or \"q\" to quit: ";
	while (std::cin >> str and "q" != str){
		AnalyzePolindrom(str) ? std::cout << "\n" << str << " is a polindrom.\n" :
		std::cout << "\n" << str << " isn't a polindrom.\n";
		std::cout << "Enter string or \"q\" to quit: ";
	}
	std::cout << "\nBye.\n";
	system("pause");
	return 0;
}

bool AnalyzePolindrom(std::string & str) { // return true if the argument is polindrom
	for (int i = str.size()-1, j = 0; i > j; --i, ++j)
		if (str[i] != str[j])
			return false;
	return true;
}