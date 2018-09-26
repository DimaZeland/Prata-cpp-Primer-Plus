#include "MyClass.h"

int main() {

	MyClass* pObject = new MyClass;
	// Exercise 1
	cout << "\nExercise 1\n";
	pObject->OutputLine(pObject->GetpItsStr(), pObject->GetitsCalls());
	// Exercise 2
	cout << "\nExercise 2\n";
	CandyBar* pCand = new CandyBar;
	pObject->DefinitionCandyBar(*pCand);
	pObject->ShowCandyBar(*pCand);
	// Exercise 3
	cout << "\nExercise 3\n";
	std::string str = "cpp is the best programming language";
	cout << "\nEnter a string (q to quit): ";
	cin >> str;
	while (str != "q") {
		pObject->UppercaseTranslation(str);
		cout << str << endl;
		cout << "\nNext string (q to quit): ";
		cin >> str;
	}
	cout << "\nBye.";
	pObject->UppercaseTranslation(str);
	cout << str << endl;

	delete pObject, pCand;
	pObject = NULL, pCand = NULL;
	system("pause");
	return 0;
}
