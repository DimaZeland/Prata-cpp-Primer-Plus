#include "Person.h"

Person::Person(const string & ln, const char * fn): lname(ln) { // #2
	int i = 0;
	for (; i < LIMIT || '\0' != fn[i]; ++i) // copy fn* to fname[LIMIT]
		fname[i] = fn[i];
	'\0' == fn[i] ? fname[i] = '\0' : fname[LIMIT] = '\0'; // add a zero terminal character at the end of the line
}
													   // the following methods display lname and fname
void
Person::Show() const { // firstname lastname format
	cout << "\nlast name " << this->lname << ", first name " << this->fname << '\n';
}

void
Person::FormalShow() const { // lastname, firstname format
	cout << "\nfirst name " << this->fname << ", last name " << this->lname << '\n';
}