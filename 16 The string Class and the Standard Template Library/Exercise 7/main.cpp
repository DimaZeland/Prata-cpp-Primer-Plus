#include<algorithm>
#include<ctime>
#include <iostream>
#include<vector>


std::vector<int> Lotto(int range, int numbers); // return winner numbers

int main() {
	srand(time(0));
	std::cout << "Enter the number of numbers on the lottery card, as well as the number of randomly selected numbers: ";
	int range = 0, numbers = 0;
	std::cin >> range >> numbers;
	std::vector<int> winners;
	winners = Lotto(range, numbers);
	std::cout << "\nThe winning numbers of the Lottery \"" << numbers << " out of " << range << "\" are the following numbers: ";
	for (int x : winners)
		std::cout << x << ' ';
	std::cout << ".\n";

	system("pause");
	return 0;
}

std::vector<int> Lotto(int range, int numbers) { // return winner numbers
	std::vector<int> buf;
	for (int i = 0; i < range; ++i)
		buf.push_back(i);
	
	int number = rand() % 100;
	for(int i = 0; i < number; ++i)
	std::random_shuffle(buf.begin(), buf.end());

	std::vector<int> result;
	for (int i = 0; i < numbers; ++i)
		result.push_back(buf.at(i));
	return result;
}