#include "Port.h"

Port::Port(const char * br, const char * st, int b):bottles(b) { // explicit constructor
	int len = strlen(br);
	brand = new char[len + 1];
	strcpy(brand, br);
	brand[len] = '\0';
	strcpy(style, st);
}

Port::Port(const Port & p): bottles(p.bottles) { // copy constructor
	int len = strlen(p.brand);
	brand = new char[len + 1];
	strcpy(brand, p.brand);
	brand[len] = '\0';
	strcpy(style, p.style);
}

Port &
Port::operator=(const Port & p) {
	if (this == &p)
		return *this;
	delete[]brand;
	int len = strlen(p.brand);
	brand = new char[len + 1];
	strcpy(brand, p.brand);
	brand[len] = '\0';
	strcpy(style, p.style);
	bottles = p.bottles;
	return *this;
}

Port &
Port::operator+=(int b) { // adds b to bottles
	bottles += b;
	return *this;
}

Port &
Port::operator-=(int b) { // subtracts b from bottles, if available
	bottles = bottles >= b ? bottles - b : bottles;
	return *this;
}

void
Port::Show() const {
	std::cout << "\nBrand: " << brand << "\nKind: " << style << "\nBottles: " << bottles << std::endl;
}

ostream & operator<<(ostream & os, const Port & p) {
	os << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}

VintagePort::VintagePort():Port("none", "vintage"), year(0) {
	nickname = new char[11];
	strcpy(nickname,"noNickName\n");
}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y): Port(br, "vintage", b), year(y) {
	int len = strlen(nn);
	nickname = new char[len + 1];
	strcpy(nickname, nn);
	nickname[len] = '\n';
}

VintagePort::VintagePort(const VintagePort & vp): Port(vp) {
	year = vp.year;
	int len = strlen(vp.nickname);
	nickname = new char[len + 1];
	strcpy(nickname, vp.nickname);
	nickname[len] = '\n';
}

VintagePort &
VintagePort::operator=(const VintagePort & vp) {
	if (this == &vp)
		return *this;
	Port::operator=(vp);
	year = vp.year;
	delete[] nickname;
	int len = strlen(vp.nickname);
	nickname = new char[len + 1];
	strcpy(nickname, vp.nickname);
	nickname[len] = '\n';
	return *this;
}

void
VintagePort::Show() const {
	Port::Show();
	cout << ", nickname: " << nickname << ", year: " << year << std::endl;
}

ostream & operator<<(ostream & os, const VintagePort & vp) {
	os << (const Port &) vp;
	os << ", nickname: " << vp.nickname << ", year: " << vp.year << std::endl;
	return os;
}
