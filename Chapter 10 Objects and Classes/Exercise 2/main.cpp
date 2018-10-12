#include "Person.h"

int main()
{
	Person one; // use default constructor
	Person two("Smythecraft"); // use #2 with one default argument
	Person three("Dimwiddy", "Sam"); // use #2, no defaults
	one.Show();
	cout << endl;
	one.FormalShow();
	two.Show();
	cout << endl;
	two.FormalShow();
	three.Show();
	cout << endl;
	three.FormalShow();

	system("pause");
	return 0;
}
