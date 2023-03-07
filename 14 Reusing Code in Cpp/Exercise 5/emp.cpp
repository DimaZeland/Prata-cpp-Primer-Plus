#include "emp.h"

abstr_emp::abstr_emp()
	: fname(" "), lname(" "), job(" ") {}

abstr_emp::abstr_emp(const std::string & fn, const std::string & ln, const std::string & j)
	: fname(fn), lname(ln), job(j) {}

void
abstr_emp::ShowAll() const { // labels and shows all data
	std::cout << "\nfirst name: " << fname << ", last name: " << lname << ", job: " << job << std::endl;
}

void
abstr_emp::SetAll() { // prompts user for values
	std::cout << "\nEnter the first name: ";
	std::cin >> fname;
	std::cout << "\nEnter the last name: ";
	std::cin >> lname;
	std::cout << "\nEnter the job: ";
	std::cin >> job;
}

std::ostream &
operator<<(std::ostream & os, const abstr_emp & e) {
	os << "\nFirst name: " << e.fname << ", last name: " << e.lname << std::endl;
	return os;
}

employee::employee()
	:abstr_emp() {}

employee::employee(const std::string & fn, const std::string & ln, const std::string & j)
	: abstr_emp(fn, ln, j) {}

void
employee::ShowAll() const {
	abstr_emp::ShowAll();
}

void
employee::SetAll() {
	abstr_emp::SetAll();
}

manager::manager()
	:abstr_emp() {}

manager::manager(const std::string & fn, const std::string & ln, const std::string & j, int ico)
	:abstr_emp(fn, ln, j), inchargeof(ico){}

manager::manager(const abstr_emp & e, int ico)
	: abstr_emp(e), inchargeof(ico) {}
	
manager::manager(const manager & m)
	: abstr_emp(m), inchargeof(m.inchargeof) {}

void
manager::ShowAll() const {
	abstr_emp::ShowAll();
	std::cout << "\nnumber of abstr_emps managed: " << inchargeof << std::endl;
}

void
manager::SetAll(){
	abstr_emp::SetAll();
	std::cout << "\nEnter the number of abstr_emps managed: ";
	std::cin >> inchargeof;
}

fink::fink()
	:abstr_emp() {}

fink::fink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo)
	: abstr_emp(fn, ln, j), reportsto(rpo) {}

fink::fink(const abstr_emp & e, const std::string & rpo)
	: abstr_emp(e), reportsto(rpo) {}

fink::fink(const fink & e)
	: abstr_emp(e), reportsto(e.reportsto) {}

void
fink::ShowAll() const {
	abstr_emp::ShowAll();
	std::cout << "\nto whom fink reports: " << reportsto << std::endl;
}

void
fink::SetAll(){
	abstr_emp::SetAll();
	std::cout << "\nEnter to whom fink reports: ";
	std::cin >> reportsto;
}

//class highfink : public manager, public fink // management fink
//{
//public:
highfink::highfink()
	: manager(), fink() {}

highfink::highfink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo, int ico)
	: manager(fn, ln, j, ico), fink(fn, ln, j, rpo){}

highfink::highfink(const abstr_emp & e, const std::string & rpo, int ico)
	: manager(e, ico), fink(e, rpo) {}

highfink::highfink(const highfink & h)
	: manager(h), fink(h) {}

highfink::highfink(const fink & f, int ico)
	: manager(f, ico), fink(f) {}

highfink::highfink(const manager & m, const std::string & rpo)
	: manager(m), fink(m, rpo) {}

void
highfink::ShowAll() const {
	abstr_emp::ShowAll();
	std::cout << "\nnumber of abstr_emps managed: " << InChargeOf() << std::endl <<
		"\nto whom fink reports: " << ReportsTo() << std::endl;
}

void
highfink::SetAll() {
	manager::SetAll();
	fink::SetAll();
}