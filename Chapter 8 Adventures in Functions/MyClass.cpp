#include "MyClass.h"

void
MyClass::DefinitionCandyBar(CandyBar& Obj, const char* name, double weight, int kkal) { // changing the values of members of the structure object
	
	Obj.itsName = name;
	Obj.itsWeight = weight;
	Obj.itsKkal = kkal;
}

void
MyClass::OutputLine(const char* str, int* repeat) { // output a string the specified number of times

	if (0 == *repeat) { // Output the line once if the function was not previously called
		++(*repeat);
		cout << str << endl;
	return;
	}
	else { // output lines as many times as previously called function
		cout << endl;
		for (int i = 0; i < *repeat; ++i)
			cout << str << endl;
		++(*repeat);
	}
}

void
MyClass::ShowCandyBar(CandyBar& rObj)const { // output the values of members of the structure object

	cout << "\nrObj.itsName = " << rObj.itsName << "\nrObj.itsWeight" << rObj.itsWeight << "\nrObj.itsKkal" << rObj.itsKkal << endl;
}

void
MyClass::UppercaseTranslation(std::string& str) { // changing string characters to uppercase characters

	for (int i = 0; i < str.size(); ++i)
		str[i] = std::toupper(str[i]);
} 
