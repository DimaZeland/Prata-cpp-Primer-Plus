#include <iostream>
#include<new>

struct chaff {
	char dross[20];
	int slag;
};
const int Size = 2;
chaff buffer[Size]; // memory block
chaff* pbuffer = new chaff[2];

int main(){
	std::cout << "Select memory buffer type: 0 - dynamic, 1- static: ";
	int choise = 0;
	std::cin >> choise;
	chaff* pArr = choise ? new (buffer) chaff[Size] : new (pbuffer) chaff[Size]; // selection of buffer type for dynamic array allocation
	
	for (int i = 0; i < Size; ++i) {
		std::cout << "\nObject " << i+1 << "\nEnter dross: ";
		std::cin >> pArr[i].dross;
		std::cout << "\nEnter slag: ";
		std::cin >> pArr[i].slag;
	}

	for (int i = 0; i < Size; ++i)
		std::cout << "\nObject " << i + 1 << "\ndross: " << pArr[i].dross <<
			"\nslag: " << pArr[i].slag << std::endl;

	if(!choise) // if the buffer for allocating a dynamic array was itself dynamically created
		delete[] pArr;
	pArr = NULL;
	system("pause");
	return 0;
}
