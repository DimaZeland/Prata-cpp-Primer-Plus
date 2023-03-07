#include "plorg.h"

Plorg::Plorg(const char* myName, int consIndex): MyCI(consIndex){
	int i = 0;
	for (; i < 19 and '\0' != myName[i]; ++i)
		Myname[i] = myName[i];
	'\0' == myName[i] ? Myname[i] = '\0' : Myname[19] = '\0';
}

void
Plorg::Show()const { //cout object data
	cout << "\nObject name " << this->Myname << ", Object contentment index " << this->MyCI << '\n';
}
