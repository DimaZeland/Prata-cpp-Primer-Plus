// exc_mean.h  -- exception classes for hmean(), gmean()
#include <iostream>
#include<stdexcept>
#include<string>
#include <sstream>

template <typename T>
std::string toString(T val)
{
	std::ostringstream oss;
	oss << val;
	return oss.str();
}

class bad_hmean: public std::logic_error
{
private:
    double v1;
    double v2;
public:
    bad_hmean(double a = 0, double b = 0) : logic_error("exception"), v1(a), v2(b){}
    void mesg();
	virtual std::string what();
};

inline void bad_hmean::mesg()
{   
    std::cout << "hmean(" << v1 << ", " << v2 <<"): "
              << "invalid arguments: a = -b\n";
}

class bad_gmean: public std::logic_error
{
public:
    double v1;
    double v2;
    bad_gmean(double a = 0, double b = 0) : logic_error("exception"), v1(a), v2(b){}
    const char * mesg();
	virtual std::string what();
};

inline const char * bad_gmean::mesg()
{  
    return "gmean() arguments should be >= 0\n";
}

std::string
bad_hmean::what() {
	return "\nfunction hmean(" + toString(v1) +", " + toString(v2) + "): invalid arguments: a = -b\n";
}

std::string
bad_gmean::what() {
	return "\nfunction gmean(" + toString(v1) + ", " + toString(v2) + "): arguments should be >= 0\n";
}