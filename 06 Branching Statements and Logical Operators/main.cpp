#include "MyClass.h"

int main(){

	MyClass* pObject = new MyClass;

	// Task 1
	pObject->KeyboardInputConversions();
	// Task 2
	pObject->AccountingDonations();
	// Task 3
	pObject->ShowsMenu();
	// Task 4
	pObject->DisplayBopMembers();
	// Task 5
	pObject->TaxCalculate();
	// Task 6
	pObject->ConclusionPatrons();
	// Task 7
	pObject->ReadingWords();
	// Task 8
	pObject->ReadingFile();
	// Task 9
	pObject->ConclusionPatronsFile();

	delete pObject;
	pObject = NULL;

	system("pause");
	return 0;

}
