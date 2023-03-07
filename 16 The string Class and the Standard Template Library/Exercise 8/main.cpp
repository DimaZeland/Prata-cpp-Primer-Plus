#include<algorithm>
#include <iostream>
#include<list>
#include<string>

int main() {
	std::list<std::string> MatFriend, PatFriend;
	std::cout << "Enter through the gap Matt's list of friends and <q> to end: ";
	std::string name_buf;
	while (std::cin >> name_buf and "q" != name_buf)
		MatFriend.push_back(name_buf);
	MatFriend.sort();
	std::cout << "\nThe Matt's list of friends:\n";
	for (std::string x : MatFriend)
		std::cout << x << '\n';

	name_buf = " ";
	std::cout << "Enter through the gap Patt's list of friends and <q> to end: ";
	while (std::cin >> name_buf and "q" != name_buf)
		PatFriend.push_back(name_buf);
	PatFriend.sort();
	std::cout << "\nThe Patt's list of friends:\n";
	for (std::string x : PatFriend)
		std::cout << x << '\n';
	
	MatFriend.merge(PatFriend); // MatFriend + PatFriend
	MatFriend.unique(); // remove duplicate neighbor names

	std::cout << "\nList of all invited guests:\n";
	for (std::string x : MatFriend)
		std::cout << x << '\n';
	std::cout << std::endl;

	system("pause");
	return 0;
}