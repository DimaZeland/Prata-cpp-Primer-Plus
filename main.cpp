#include"MyClass.h"

int main()
{
	MyClass *Object = new MyClass;

	//Task 1: the sum of a range of two numbers
	int a = 0, b = 0;
	cout << "Enter two integer number: ";
	cin >> a >> b;
	cout << "\nThe sum of a range of two numbers is " << Object->Sum2Number(a, b) << endl;
	// Task 2: return of the factorial number
	cout << "\nTable of factorials of numbers from 1 to 100:\n";
	Object->ReturnFactorial();
	// Task 3: counting the sum of the entered numbers
	Object->CountingSumNumbers();
	//Task 4: calculation of the Balance Sheet
	Object->CalculationBalance(1000.0, 1000.0);
	//Task5: book Sales Accounting
	Object->BookSales();
	// Task 6: three year book Sales Accounting 
	Object->BookSales3Years();
	// Task 7: displaying information about the car catalog
	Object->CarCatalog();
	//Task 8: counting the number of entered words
	Object->ReadingWords();
	// Task 9: counting the number of entered words (using std::string)
	Object->ReadingWordsS();
	//Task 10: displaying entered number of stars
	cout << "Entered the number of stars: ";
	int num;
	cin >> num;
	Object->DispayingStars(num);

	delete Object, Object = NULL; // clearing dynamic memory and nulling address pointers
	
	system("pause");
	return 0;
}
