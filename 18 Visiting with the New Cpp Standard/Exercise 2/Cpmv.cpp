#include"Cpmv.h"

Cpmv::Cpmv() {
	cout << "\nConstrucor Cpmv() called.\n";
	pi = new Info;
	pi->qcode = "\0";
	pi->zcode = "\0";
}

Cpmv::Cpmv(std::string q, std::string z){
	cout << "\nConstrucor Cpmv(std::string, std::string) called.\n";
	pi = new Info;
	pi->qcode = q;
	pi->zcode = z;
}

Cpmv::Cpmv(const Cpmv & cp) {
	cout << "\nCopy-construcor Cpmv(const Cpmv &) called.\n";
	if (this == &cp)
		return;
	pi = new Info;
	pi->qcode = { cp.pi->qcode };
	pi->zcode = { cp.pi->zcode };
}

Cpmv::Cpmv(Cpmv && mv) {
	cout << "\nTransfer-construcor Cpmv(Cpmv &&) called.\n";
	if (this == &mv)
		return;
	pi = new Info;
	pi->qcode = { mv.pi->qcode };
	pi->zcode = { mv.pi->zcode };

	mv.pi->qcode = "\0";
	mv.pi->zcode = "\0";
	mv.pi = nullptr;
}

Cpmv::~Cpmv() {
	cout << "\nDesstrucor ~Cpmv() called.\n";
	delete	pi;
	pi = nullptr;
}

Cpmv &
Cpmv::operator=(const Cpmv & cp) {
	cout << "\noperator=(const Cpmv &) called.\n";
	if (this == &cp)
		return *this;
	
	delete	pi;
	pi = new Info;
	pi->qcode = { cp.pi->qcode };
	pi->zcode = { cp.pi->zcode };
	return *this;
}

Cpmv &
Cpmv::operator=(Cpmv && mv) {
	cout << "\noperator=(const Cpmv &&) called.\n";
	if (this == &mv)
		return *this;

	delete	pi;
	pi = new Info;
	pi->qcode = { mv.pi->qcode };
	pi->zcode = { mv.pi->zcode };
	return *this;
}

Cpmv
Cpmv::operator+(const Cpmv & obj) const {
	cout << "\noperator+(const Cpmv &, const Cpmv &) called.\n";
	Cpmv one;
	one.pi->qcode = (!pi) ? obj.pi->qcode : pi->qcode + obj.pi->qcode; // if first argument is "\0"
	one.pi->zcode = (!pi) ? obj.pi->zcode : pi->zcode + obj.pi->zcode; // if first argument is "\0"
	return one;
}

void
Cpmv::Display() const {
	if (pi) // if pi != nullptr
		cout << "\npi adress: " << pi <<
		"\npi->qcode = \"" << (*pi).qcode << "\", qcode adress: " << &pi->qcode <<
		"\npi->zcode = \"" << pi->zcode << "\", zcode adress: " << &pi->zcode << endl;
	else
		cout << "\npi adress: " << pi << endl;
}