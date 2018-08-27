#include"MyClass.h"

void
MyClass::BookSales(void)const { // book Sales Accounting

	std::string Month[12]{ "January", "February", "March", "April", "May" , "June" , "July" , "August" , "September" , "October" , "November" , "December" };
	unsigned int Sales[12]{};
	int totalSold = 0;

	cout << "Please enter the results of sales of books for each month:\n";
	for (int i = 0; i < 12; ++i) { // entering sales data
		cout << Month[i] << ":\t";
		cin >> Sales[i];
		cout << '\n';
	}

	for (int x : Sales) // calculation of annual sales amount
		totalSold += x;
	cout << "Annual sales amount is " << totalSold << " books\n";
}

void
MyClass::BookSales3Years(void)const { // book Sales Accounting

	std::string Month[3][12]{ {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"},
	{ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" },
	{ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" } };
	unsigned int Sales[3][12]{};
	int totalSold[4]{};

	for (int i = 0; i < 3; ++i) { // entering years's sales data
		cout << "Please enter the results of sales of books for each month:\n";
		for (int j = 0; j < 12; ++j) { // entering month's sales data
			cout << Month[i][j] << ":\t";
			cin >> Sales[i][j];
			cout << '\n';
			totalSold[i] += Sales[i][j]; // calculation of annual sales amount

		}
		totalSold[3] += totalSold[i]; // calculation of 3-years sales amount
	}

	for (int x = 0; x < 3; ++x)
		cout << "Annual sales amount are " << totalSold[x] << " books in " << x + 1 << " year.\n";
	cout << "Three years sales amount are " << totalSold[3] << " books.\n";
}

void
MyClass::CalculationBalance(float Dafna, float Kleo)const { // calculation of the Balance Sheet

	float *DafnaBalance = new float(Dafna), *KleoBalance = new float(Kleo);

	for (int i = 1; *DafnaBalance >= *KleoBalance; ++i) { // derivation of return on investment
		*DafnaBalance += 500, *KleoBalance *= 1.25,
			cout << i << ".\tDafna Balance " << *DafnaBalance << "$, Kleo Balance " << *KleoBalance << "$, " << int((*KleoBalance - 1000) / (i * 10)) << "% years\n";
	}

	delete DafnaBalance, KleoBalance; // clearing dynamic memory and nulling address pointers
	DafnaBalance = NULL, KleoBalance = NULL;
}

void
MyClass::CarCatalog()const { // displaying information about the car catalog

	cout << "Enter the number of cars: ";
	unsigned int carNumbers = 0;
	cin >> carNumbers;

	std::vector <MyClass::Car> CarsCatalog;
	//union form {
	//	form() { std::memset(this, 0, sizeof(form)); }
	//	~form(){}
	//	std::string Name;
	//	int Year;
	//};
	//form test;
	Car test;

	for (int i = 0; i < carNumbers; ++i) { // entering information about car collection instances
		cout << "Enter the manufactured: ";
		cin >> test.manufacturer;
		cout << "Please enter the year of manufacture: ";
		cin >> test.yearRelease;
		CarsCatalog.push_back(test);
	}

	cout << "Your collection:\n";
	for (Car x : CarsCatalog)
		cout << x.yearRelease << ' ' << x.manufacturer << endl;
}

void
MyClass::CountingSumNumbers(void)const { // counting the sum of the entered numbers

	int *number = new int(0), *sum = new int(0);
	//cout << endl;
	cin.get();
	do {
		*sum += *number;
		cout << "\nSum = " << *sum << "\nPlease enter the number: ";
		cin >> *number;
	} while (*number);

	delete number, sum;
	number = NULL, sum = NULL;
}

void
MyClass::DispayingStars(int& value)const { // displaying entered number of stars
	cout.fill('.');
	for (int i = 0; i < value; ++i) {
		cout << std::setw(value - i);
		for (int j = 0; j < value && i >= j; ++j)
			cout << '*';
		cout << endl;
	}
}

void
MyClass::ReturnFactorial(void) const { // return of the factorial number

	const int ArSize = 101;
	std::array <long double, ArSize> factorials;
	factorials[1] = factorials[0] = 1;
	for (int i = 2; i < ArSize; i++)
		factorials[i] = i * factorials[i - 1];
	for (int i = 0; i < ArSize; i++)
		std::cout << i << "! = " << factorials[i] << std::endl;
}

void
MyClass::ReadingWords(void)const { // counting the number of entered words

	char word[25]{};

	cout << "Please enter the text (\"done\" to exit): ";
	int i = 0;
	for (; strcmp(word, "done"); ++i) {
		cin >> word;
		cout << word << ' ';
	}

	cout << "You entered " << i - 1 << " words\n";
}

void
MyClass::ReadingWordsS(void)const { // counting the number of entered words (using std::string)

	std::string word{};

	cout << "Please enter the text (\"done\" to exit): ";
	int i = 0;
	for (; word != "done"; ++i) {
		cin >> word;
		cout << word << ' ';
	}

	cout << "You entered " << i - 1 << " words\n";
}

int
MyClass::Sum2Number(int & a, int& b) const { // return the sum of a range of two numbers

	int* sum = new int(0);
	for (int i = a; i <= b; ++i)
		*sum += i;

	return *sum;
}