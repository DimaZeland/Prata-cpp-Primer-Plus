// stonewt.cpp -- Stonewt methods
#include <iostream>
using std::cout;
#include "stonewt.h"

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs, Type inter) 
{
	interfc = inter;
	stone = int(lbs) / Lbs_per_stn;    // integer division
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs, Type inter)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
	interfc = inter;
}

Stonewt::Stonewt(): interfc(POUND)          // default constructor, wt = 0
{
	stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt()         // destructor
{
}

std::ostream& operator<< (std::ostream & os, Stonewt & v) {
	switch (v.interfc){
	case 0:
		os << '\n' << v.stone << " stones\n";
		break;
	case 1:
		os << '\n' << v.stone << " stones " << v.pds_left << " pounds\n";
		break;
	case 2:
		os << '\n' << v.pounds << " pounds\n";
		break;
	default:
		os << "\nObject variable member interfc has invalid matters\n";
		break;
	}
	return os;
}

Stonewt Stonewt::operator+(Stonewt & v){
	Stonewt Sum;
	Sum.interfc = this->interfc;
	Sum.stone = int(this->pounds + v.pounds) / Lbs_per_stn;
	Sum.pds_left = int(this->pounds + v.pounds) % Lbs_per_stn + (this->pounds + v.pounds) - int(this->pounds + v.pounds);
	Sum.pounds = this->pounds + v.pounds;
	return Sum;
}
Stonewt Stonewt::operator-(Stonewt & v) {
	Stonewt Dif;
	Dif.interfc = this->interfc;
	Dif.stone = int(this->pounds - v.pounds) / Lbs_per_stn;
	Dif.pds_left = int(this->pounds - v.pounds) % Lbs_per_stn + (this->pounds - v.pounds) - int(this->pounds - v.pounds);
	Dif.pounds = this->pounds - v.pounds;
	return Dif;
}
Stonewt Stonewt::operator*(Stonewt & v) {
	Stonewt s;
	s.stone = int(pounds*v.pounds) / Lbs_per_stn;    // integer division
	s.pds_left = int(pounds*v.pounds) % Lbs_per_stn + (pounds*v.pounds) - int(pounds*v.pounds);
	s.pounds *= pounds * v.pounds;
	return s;
}