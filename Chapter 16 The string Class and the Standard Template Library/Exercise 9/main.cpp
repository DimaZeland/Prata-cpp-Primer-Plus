#include<algorithm>
#include<ctime>
#include <iostream>
#include<list>
#include<string>
#include<vector>

int main() {
	srand(time(0));
	std::vector<int> vi0;
	std::cout << "Enter the desired number of sorted items (recommended from 10000): ";
	int SIZE;
	std::cin >> SIZE;
	for (int i = 0; i < SIZE; ++i)
		vi0.push_back(rand());

	std::vector<int> vi(vi0);
	std::list<int> li;

	for (int i = 0; i < SIZE; ++i)
		li.push_back(vi.at(i));

	std::cout << "\nsort(vi.begin(), vi.end()): ";
	clock_t start = clock();
	sort(vi.begin(), vi.end());
	clock_t end = clock();
	std::cout << double(end - start) / CLOCKS_PER_SEC << " sec.\n";

	std::cout << "\nli.sort(): ";
	start = clock();
	li.sort();
	end = clock();
	std::cout << double(end - start) / CLOCKS_PER_SEC << " sec.\n";

	std::copy(vi0.begin(), vi0.end(), li.begin());
	std::cout << "\nThe execution time of the mixed copying operation li in vi, sorting vi and copying the result back into li: ";
	start = clock();
	std::copy(li.begin(), li.end(), vi.begin());
	sort(vi.begin(), vi.end());
	std::copy(vi.begin(), vi.end(), li.begin());
	end = clock();
	std::cout << double(end - start) / CLOCKS_PER_SEC << " sec.\n";






	//std::list<std::string> MatFriend, PatFriend;
	//std::cout << "Enter through the gap Matt's list of friends and <q> to end: ";
	//std::string name_buf;
	//while (std::cin >> name_buf and "q" != name_buf)
	//	MatFriend.push_back(name_buf);
	//MatFriend.sort();
	//std::cout << "\nThe Matt's list of friends:\n";
	//for (std::string x : MatFriend)
	//	std::cout << x << '\n';

	//name_buf = " ";
	//std::cout << "Enter through the gap Patt's list of friends and <q> to end: ";
	//while (std::cin >> name_buf and "q" != name_buf)
	//	PatFriend.push_back(name_buf);
	//PatFriend.sort();
	//std::cout << "\nThe Patt's list of friends:\n";
	//for (std::string x : PatFriend)
	//	std::cout << x << '\n';
	//
	//MatFriend.merge(PatFriend); // MatFriend + PatFriend
	//MatFriend.unique(); // remove duplicate neighbor names

	//std::cout << "\nList of all invited guests:\n";
	//for (std::string x : MatFriend)
	//	std::cout << x << '\n';
	//std::cout << std::endl;

	system("pause");
	return 0;
}