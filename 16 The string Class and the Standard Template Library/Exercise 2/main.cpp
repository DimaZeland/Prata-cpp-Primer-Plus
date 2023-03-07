#include<cctype>
#include<iostream>
#include<string>

bool AnalyzePolindrom(const std::string &); // return true if the argument is polindrom
std::string ConvertString(const std::string &); // removes punctuation and spaces
int main() {
	std::string str = " ", str1 = " ";
	std::cout << "Enter string or \"q\" to quit: ";
	while (std::getline(std::cin,str) and "q" != str){
		str1 = ConvertString(str);
		AnalyzePolindrom(str1) ? std::cout << "\n" << str << " is a polindrom.\n" :
		std::cout << "\n" << str << " isn't a polindrom.\n";
		std::cout << "Enter string or \"q\" to quit: ";
	}
	std::cout << "\nBye.\n";
	system("pause");
	return 0;
}

bool AnalyzePolindrom(const std::string & str) { // return true if the argument is polindrom
	for (int i = str.size()-1, j = 0; i > j; --i, ++j)
		if (str[i] != str[j])
			return false;
	return true;
}

std::string ConvertString(const std::string & str) { // removes punctuation and spaces
	std::string buf;
	for (char x : str)
		if (isalnum(x)){ // is character is digit or alpha
			if (isupper(x))
				x = tolower(x);
				buf += x;
		}
			return buf;
}