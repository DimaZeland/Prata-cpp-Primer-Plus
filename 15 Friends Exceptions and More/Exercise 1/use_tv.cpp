//use_tv.cpp -- using the Tv and Remote classes
#include <iostream>
#include "tv.h"

int main()
{
    using std::cout;
    Tv s42;
	cout << "Initial settings for 42\" TV:\n";
	s42.settings();
	s42.onoff();
	s42.settings();

	Remote grey;
	grey.GetMyControlMode();
	cout << "\nChange remote control mode.\n";
	s42.SetMyControlMode(grey);
	grey.GetMyControlMode();
	s42.onoff();
	s42.settings();

    system("pause");
    return 0; 
}
