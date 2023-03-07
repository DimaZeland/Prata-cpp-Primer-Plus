#ifndef COMPLEX0_H_
#define COMPLEX0_H_
class complex
{
private:
	double myReal;
	double myImaginary;
public:
	complex(double real = 0, double imaginary = 0) : myReal(real), myImaginary(imaginary){}
	friend std::istream& operator>>(std::istream & os, complex &);
	friend std::ostream& operator<< (std::ostream & os, const complex &);
	complex operator+(complex&);
	complex operator-(complex&);
	complex operator*(complex&);
	friend complex operator*(double, complex&);
	complex& operator~();
};
#endif
