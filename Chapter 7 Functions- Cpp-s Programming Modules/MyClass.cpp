#include "MyClass.h"

void
MyClass::DisplayResults(void)const { // display the results of golf games

	cout << "\nThe results of golf games: ";
	for (double x : itsGolfResult)
		if (x)
			cout << x << ' ';
		else
			break;
	cout << "\nAverage value of the results of games: " << this->FindMeanValue() << endl;
}

void
MyClass::DisplayBox(const box one) { // display members of the structure

	cout << "box.char: " << one.maker << ", box.height: " << one.height << ", box.wight: " << one.wight <<
		", box.lenght: " << one.lenght << ", box.volume: " << one.volume << "\n";

}

void
MyClass::DisplayBoxMenu(MyClass& Obj,box& str) { // functionality of work with structure

	int choise = 0;
	cout << "\nPlease select an action: 1 - output the data value of the structure, 2 - change the value of a variable \"volume\", q - quit: ";
	while (cin >> choise) {
		system("cls");
		switch (choise)
		{
		case 1:
			Obj.DisplayBox(str);
			break;
		case 2:
			Obj.SetBoxVolume(str);
			cout << "\ndata values of the structure after changing the value of the variable \"volume\":\n";
			Obj.DisplayBox(str);
			break;
		default:
			cout << "\nWrong choice. Try again!";
			break;
		}
		cout << "\nPlease select an action: 1 - output the data value of the structure, 2 - change the value of a variable \"volume\", q - quit: ";
	}
}

void
MyClass::FactorialMenu(void)const {  //derivation of the factorial of given numbers

	int number = 0;
	cout << "Please enter the number <1-25> to find factorial or <q> to quit: ";
	while (cin >> number) {
		system("cls");
		cout << number << "!: " << this->GetFactorial(number) << '\n';
		cout << "Please enter the number <1-25> to find factorial or <q> to quit: ";
	}
	cout << "\nBye!";
}

void
MyClass::Fill_array(double* itsArr, int size) { // array filling

	cout << "Introduction the value of array elements: ";
	for (int i = 0; i < size and  cin >> itsArr[i]; ++i);
}

double
MyClass::FindMeanValue()const { // Find the mean value array's itsGolfResult elements

	double average{ 0 };
	int games{ 0 };
	for (double x : itsGolfResult)
		if (x) {
			average += x;
			++games;
		}
		else
			break;
	return games ? average / games : 0;
}

int
MyClass::GetFactorial(int number)const { // derivation the factorial of given numbers

	if (0 == number)
		return 0;
	else if (1 == number)
		return 1;
	else
		return number * this->GetFactorial(number - 1);
}

long double
MyClass::Probability(unsigned numbers, unsigned picks, unsigned meganumberSize) {// taking into account the chance of winning in the American lottery

	long double result = 1.0;  // here come some local variables
	long double n;
	unsigned p;

	for (n = numbers, p = picks; p > 0; n--, p--)
		result = result * n / p;
	result *= meganumberSize;
	return result;
}

void
MyClass::Reserve_array(double* Arr, int size) { // changing the order of array elements
	--size;
	for (int i = 1; i < size - i; ++i)
		std::swap(Arr[i], Arr[size - i]);
}

void
MyClass::SetitsGolfResult(void) { // set the results of 10 golf games

	cout << "Enter the result of Golf game 1 or <q> to quit: ";
	for (int i = 0; cin >> itsGolfResult[i]; ++i)
		if (i >= 9)
			break;
		else
			cout << "Enter the result of Golf game " << i + 2 << " or <q> to quit: ";
	cout << "\nThanks for information!\n";
}

void
MyClass::Show_array(double* Arr, int size) { // deducing the values of array elements

	for (int i = 0; i < size; ++i)
		cout << Arr[i] << ' ';
	cout << '\n';
}
