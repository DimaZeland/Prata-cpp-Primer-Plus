// pe14-5.cpp
// useemp1.cpp -- using the abstr_emp classes
#include <iostream>
#include<memory>
#include<fstream>
#include "emp.h"
using namespace std;

const int MAX = 10;
bool FileIsExist(std::string filePath); // Check for file existence
void SetArr(abstr_emp* pc[], int& index); // write data to an array
int main(void)
{

	abstr_emp* pc[MAX];
	int index = 0;
	const char* file_name = "C:\\Users\\User\\source\\repos\\Prata\\Prata\\File.txt";

	if (!FileIsExist(file_name)) { // if the program is running for the first time
		fstream File(file_name, std::ios_base::in | std::ios_base::out | std::ios_base::app);

		SetArr(pc, index); // write data to an array

		std::cout << "\nEntry List:";
		for (int i = 0; i < index; ++i) // data mapping from array
			pc[i]->ShowAll();

		for (int i = 0; i < index; ++i) // writing data from an array to a file
			pc[i]->writeall(File);
		File.close();
	}
	else { // if the program is running a second time
		fstream File(file_name, std::ios_base::in | std::ios_base::out | std::ios_base::app);

		enum classkind { Employee = 1, Manager, Fink, HighFink };

		int classtype, i = 0;
		while ((File >> classtype).get() != EOF) { // saving data from file to array
			switch (classtype) {
			case Employee: pc[i] = new employee;
				break;
			case Manager: pc[i] = new manager;
				break;
			case Fink: pc[i] = new fink;
				break;
			case HighFink: pc[i] = new highfink;
				break;
			default:
				break;
			}
			pc[i++]->getall(File); // saving data from file to array
		}
		File.close();
		index = i;
		std::cout << "\n New List:";
		for (int i = 0; i < index; ++i) // data mapping from array
			pc[i]->ShowAll();

		std::cout << "\nWould you like to write new data to file <Y/N>: ";
		char ch;
		std::cin >> ch;
		if ('Y' == ch or 'y' == ch) {
			int index_last_start = index;
			SetArr(pc, index); // write data to an array

			File.open(file_name, std::ios_base::in | std::ios_base::out | std::ios_base::app);

			for (int i = index_last_start; i < index; ++i) // writing data from an array to a file
				pc[i]->writeall(File);

			File.close();

			std::cout << "\n New List:";
			for (int i = 0; i < index; ++i) // data mapping from array
				pc[i]->ShowAll();

		}
	}

	system("pause");
	return 0;
}

bool FileIsExist(std::string filePath) {
	bool isExist = false;
	std::ifstream fin(filePath.c_str());

	if (fin.is_open() and isdigit(fin.get()))
		isExist = true;

	fin.close();
	return isExist;
}

void SetArr(abstr_emp* pc[], int& index) { // write data to an array
	std::cout << "\nPlease enter the type of object being created:\n1 - <employe>\n2 - manager\n3 - fink\n4 - highfink\n<q> enter: ";
	int choise;
	while (std::cin >> choise and index < MAX) { // select the type of object and save the data to the array
		switch (choise) {
		case 1:
			pc[index] = new employee;
			break;
		case 2:
			pc[index] = new manager;
			break;
		case 3:
			pc[index] = new fink;
			break;
		case 4:
			pc[index] = new highfink;
			break;
		default:
			pc[index] = new employee;
			break;
		}
		pc[index]->SetAll();
		++index;
		std::cout << "\nPlease enter the type of object being created:\n1 - <employe>\n2 - manager\n3 - fink\n4 - highfink\n<q> enter: ";
	}
}