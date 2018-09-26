#pragma once

#include<algorithm>
#include<cctype>
#include <iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;

struct CandyBar {
public:
	CandyBar(): itsName(" "), itsWeight(0.0), itsKkal(0){}
	CandyBar(std::string name, double weight, int kkal) : itsName(name), itsWeight(weight), itsKkal(kkal) {}
	~CandyBar() {}

	std::string itsName;
	double itsWeight;
	int itsKkal;

};

class MyClass
{
public:
	MyClass(): pItsStr("Hello, World!"), itsCalls(0) {}
	~MyClass() {}
	// class methods
	inline const char* GetpItsStr(void) { return this->pItsStr; }
	inline int* GetitsCalls(void) { return &(this->itsCalls); }
	void DefinitionCandyBar(CandyBar&, const char* = "Millennium Munch", double = 2.85, int = 350); // changing the values of members of the structure object
	void OutputLine(const char*, int* = 0); // output a string the specified number of times 
	void ShowCandyBar(CandyBar&)const; // output the values of members of the structure object
	void UppercaseTranslation(std::string&); // changing string characters to uppercase characters
private:
	const char* pItsStr;
	int itsCalls;
};