// stonewt.h -- definition for the Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_
class Stonewt
{
public:
	enum Type { STOUN, STOUNPOUNDS, POUND };
private:
	enum { Lbs_per_stn = 14 };      // pounds per stone
	int stone;                    // whole stones
	double pds_left;              // fractional pounds
	double pounds;                // entire weight in pounds
	Type interfc;
public:
	Stonewt(double lbs, Type = POUND);          // constructor for double pounds
	Stonewt(int stn, double lbs, Type = STOUN); // constructor for stone, lbs
	Stonewt();                    // default constructor
	~Stonewt();
	friend std::ostream& operator<< (std::ostream & os, Stonewt &);
	Stonewt operator+(Stonewt &);
	Stonewt operator-(Stonewt &);
	Stonewt operator*(Stonewt &);
	bool operator>(Stonewt &);
	bool operator>=(Stonewt &);
	bool operator==(Stonewt &);
	bool operator<(Stonewt &);
	bool operator<=(Stonewt &);
	bool operator!=(Stonewt &);
};
#endif
