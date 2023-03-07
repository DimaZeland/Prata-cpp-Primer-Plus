#include "MyClass.h"

int main() {

	MyClass* pObject = new MyClass;
	// Exercise 1
	double *pNum1 = new double(0), *pNum2 = new double(0);
	do {
		cout << "\nEnter two numbers: ";
		cin >> *pNum1 >> *pNum2;
		cout << "The average harmonic of two numbers is " << pObject->GetAverageHarmonic(pNum1, pNum2) << endl;
	} while (*pNum1 and *pNum2);
	delete pNum1, pNum2;
	pNum1 = pNum2 = NULL;
	// Exercise 2
	pObject->SetitsGolfResult();
	pObject->DisplayResults();
	// Exercise 3
	box one;
	pObject->DisplayBoxMenu(*pObject, one);
	// Exercise 4
	cout << "\nPlease enter the number of digits to select from the field, the size of the number field, the size of the field to select the mega-number: ";
	unsigned numbers = 0, picks = 0, meganumberSize = 0;
	cin >> picks >> numbers  >> meganumberSize;
	cout << "\nChance to win in such a lottery: 1 of " << pObject->Probability(numbers, picks, meganumberSize) << '\n';
	// Exercise 5
	pObject->FactorialMenu();
	// Exercise 6
	pObject->Fill_array(pObject->itsArr);
	cout << "\nitsArray[]:\n";
	pObject->Show_array(pObject->itsArr);
	pObject->Reserve_array(pObject->itsArr);
	cout << "\nitsArray[] after reserve:\n";
	pObject->Show_array(pObject->itsArr);
	// Exercise 10
	double(MyClass::*pFunc)(double, double) = &MyClass::Sum; // initializing function pointer

	double(MyClass::*pf[2])(double, double) = { &MyClass::Sum , &MyClass::Multiplication }; // initializing an array of function pointers
	cout << "\nEnter two numbers and select the function <1 - Sum, 2 - Multiplication>: ";
	int a = 0, b = 0, func = 0;
	while (cin >> a >> b >> func and (1 == func or 2 == func)) {
		if (1 == func)
			cout << pObject->calculate(a, b, pf[0]) << endl;
		else
			cout << pObject->calculate(a, b, pf[1]) << endl;
		cout << "\nEnter two numbers and select the function <1 - Sum, 2 - Multiplication>: ";
	}


	delete pObject;
	pObject = NULL;

	system("pause");
	return 0;
}
