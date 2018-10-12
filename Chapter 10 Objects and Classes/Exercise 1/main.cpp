#include "BankAccount.h"

int main()
{
	BankAccount* pObj = new BankAccount("Dima Zeland", "123456", 1000000);
	std::string invitation = "\nMenu:\n1 - account information\n2 - top up account\n3 - withdraw funds\n0 - exit\nPlease enter a choise: ";
	cout << invitation;
	int choise = 0;
	double depo = 0;
	while (cin >> choise and 0 != choise) {
		switch (choise){
		case 1: 
			pObj->show();
			cout << invitation;
			break;
		case 2:
			cout << "\nPlease enter refill amount($): ";
			cin >> depo;
			pObj->deposit(depo);
			cout << invitation;
			break;
		case 3:
			cout << "\nPlease enter withdrawal amount($): ";
			cin >> depo;
			pObj->withdraw(depo);
			cout << invitation;
			break;
		default:
			cout << "\nWrong input!\n";
			break;
		}
	}
	cout << "\nBye!\n";

	delete pObj;
	pObj = NULL;

	system("pause");
	return 0;
}
