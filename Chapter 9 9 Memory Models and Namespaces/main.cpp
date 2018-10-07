#include "golf.h"

extern const int Len;

int main()
{
	std::cout << "\nEnter the numbers of users: ";
	int users = 0;
	std::cin >> users;

	golf* pUsers = new golf[users];

	std::cout << "\nselect the way to fill the array of structures:\n1 - int setgolf(& golf), 2 - void setgolf(golf & g, const char * name, int hc): ";
	int choise = 0;
	std::cin >> choise;
	switch (choise) {
	case 1: {
		for (int i = 0; i < users; ++i) { // data entry for the structure with include function int setgolf(& golf);
			std::cout << "User " << i + 1 << ": ";
			setgolf(pUsers[i]);
			if (' ' == pUsers[i].fullname[0] || '\0' == pUsers[i].fullname[0])
				break;
		}
		break;
	}
	case 2: {
		char NameArr[Len] = {};
		int hc = 0;
		for (int i = 0; i < users; ++i) { // data entry for the structure with include function void setgolf(golf & g, const char * name, int hc);
			std::cout << "Please enter user " << i + 1 << " name: ";
			std::cin >> NameArr;
			std::cout << "Please enter user " << i + 1 << " handicap: ";
			std::cin >> hc;
			setgolf(pUsers[i], NameArr, hc);
			if (' ' == pUsers[i].fullname[0] || '\0' == pUsers[i].fullname[0])
				break;
		}
		break;
	}
	default:
		std::cout << "\nInvalid choise. Bye!\n";
		break;
	}

	std::cout << "\noutput of the array of player structures:\n";
	for (int i = 0; i < users; ++i) { // output the value of the array of the structure member 
		std::cout << "\nUser " << i + 1 << ":\n";
		showgolf(pUsers[i]);
	}

	std::cout << "\nDo you have the desire to change the value of the handicap for an individual player?\n1 - Yes, 0 - No: ";
	std::cin >> choise;
	if (choise) {
		int player = 0;
		std::cout << "Enter the number of player and new value of the handicap: ";
		std::cin >> player >> choise;
		handicap(pUsers[player - 1], choise);
	}

	std::cout << "\noutput of the array of player structures:\n";
	for (int i = 0; i < users; ++i) { // output the value of the array of the structure member 
		std::cout << "\nUser " << i + 1 << ":\n";
		showgolf(pUsers[i]);
	}




	delete pUsers;
	pUsers = NULL;
	system("pause");
	return 0;
}
