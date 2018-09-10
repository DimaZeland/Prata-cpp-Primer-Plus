#include <iostream>
using namespace std;

const int SLEN = 30;
struct student {
	student() : fullname{ "\0" },hobby{ "\0" },ooplevel{ 0 } {}
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};
// getinfo() has two arguments: a pointer to the first element of
// an array of student structures and an int representing the
// number of elements of the array. The function solicits and
// stores data about students. It terminates input upon filling
// the array or upon encountering a blank line for the student
// name. The function returns the actual number of array elements
// filled.
int getinfo(student pa[], int n);
// display1() takes a student structure as an argument
// and displays its contents
void display1(student st);
// display2() takes the address of student structure as an
// argument and displays the structure’s contents
void display2(const student * ps);
// display3() takes the address of the first element of an array
// of student structures and the number of array elements as
// arguments and displays the contents of the structures
void display3(const student pa[], int n);
int main()
{
	cout << "Enter class size : ";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n')
		continue;
	student * ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete[] ptr_stu;
	cout << "Done\n";
	system("pause");
	return 0;
}

int getinfo(student pa[], int n) {
	int i = 0;
	for (; i < n; ++i) {
		cout << "\nEnter fullname of " << i + 1 << " student: ";
		cin.getline((pa[i]).fullname,SLEN);
		if (' ' == (pa[i]).fullname[0])
			return i;
		cout << "\nGOOD!\n";
		cout << "\nEnter hobby of " << i + 1 << " student: ";
		cin >> (pa[i]).hobby;
		cout << "\nEnter ooplevel of " << i + 1 << " student: ";
		cin >> (pa[i]).ooplevel;
		cin.get();
		system("cls");
	}
	return n;
}

void display1(student st) {
	cout << "\nInformation about the student\nfullname: " << st.fullname <<
		"\nhobby: " << st.hobby << "\nooplevel: " << st.ooplevel << endl;
}

void display2(const student * ps) {
	cout << "\nInformation about the student\nfullname: " << ps->fullname <<
		"\nhobby: " << ps->hobby << "\nooplevel: " << ps->ooplevel << endl;

}

void display3(const student pa[], int n) {
	cout << "\nInformation about the students";
	for (int i = 0; i < n; ++i)
	cout << "\nStudent " << i+1 << "\nfullname: " << (pa[i]).fullname <<
		"\nhobby: " << (pa[i]).hobby << "\nooplevel: " << (pa[i]).ooplevel << '\n';
}