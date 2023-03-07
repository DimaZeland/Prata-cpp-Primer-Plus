// static.cpp -- using a static local variable
#include <iostream>
#include<string>

// function prototype
void strcount(const std::string& str);

int main()
{
	using namespace std;
	string str = " ";
	cout << "Enter a line:\n";
	getline(cin,str);
	while ('\0' != str[0])
	{
		strcount(str);
		cout << "Enter next line (empty line to quit):\n";
		getline(cin, str);
	}
	cout << "Bye\n";
	system("pause");
	return 0;
}

void strcount(const std::string& str)
{
	int i = 0, total = 0;
	while (str[i++])
		++total;
	std::cout << total << " characters total\n";
}
