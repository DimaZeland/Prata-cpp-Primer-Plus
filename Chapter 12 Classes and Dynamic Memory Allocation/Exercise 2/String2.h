// string1.h -- fixed and augmented string class definition

#ifndef STRING2_H_
#define STRING2_H_
#include <iostream>
using std::ostream;
using std::istream;

class String
{
private:

	int len;                // length of string
	static int num_strings; // number of objects
	static const int CINLIM = 80;  // cin input limit
public:
	char * str;             // pointer to string
	// constructors and other methods
	String(const char * s); // constructor
	String();               // default constructor
	String(const String &); // copy constructor
	~String();              // destructor
	int length() const { return len; }
	void stringlow(); // lower case letters
	void stringup(); // upper case letters
	int has(char)const; // return the number of characters in the string
	// overloaded operator methods    
	String & operator=(const String &);
	String & operator=(const char *);
	String operator+(const String &) const;
	String operator+(const char *) const;
	friend String operator+(const char * pStr, const String & Str);
	char & operator[](int i);
	const char & operator[](int i) const;
	// overloaded operator friends
	friend bool operator<(const String &st, const String &st2);
	friend bool operator>(const String &st1, const String &st2);
	friend bool operator==(const String &st, const String &st2);
	friend ostream & operator<<(ostream & os, const String & st);
	friend istream & operator>>(istream & is, String & st);
	// static function
	static int HowMany();
};
#endif
