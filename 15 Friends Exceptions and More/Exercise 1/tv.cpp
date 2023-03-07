// tv.cpp -- methods for the Tv class (Remote methods are inline)
#include <iostream>
#include "tv.h"

bool Tv::volup()
{
    if (volume < MaxVal)
    {
        volume++;
        return true;
    }
    else
        return false;
}
bool Tv::voldown()
{
    if (volume > MinVal)
    {
        volume--;
        return true;
    }
    else
        return false;
}

void Tv::chanup()
{
    if (channel < maxchannel)
        channel++;
    else
        channel = 1;
}

void Tv::chandown()
{
    if (channel > 1)
        channel--;
    else
        channel = maxchannel;
}

void Tv::settings() const
{
    using std::cout;
    using std::endl;
    cout << "TV is " << (state == Off? "Off" : "On") << endl;
    if (state == On)
    {
        cout << "Volume setting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = "
            << (mode == Antenna? "antenna" : "cable") << endl;
        cout << "Input = "
            << (input == TV? "TV" : "DVD") << endl;
    }
}

bool
Tv::SetMyControlMode(Remote& r) { // change Remote::itsMyControlMode is state is "on"
	if (state) { // if TB is on
		r.itsMyControlMode = r.itsMyControlMode ? Remote::normal : Remote::interactive;
		return true;
	} //if TV is off
	return false;
}

void
Remote::GetMyControlMode()const {
	std::cout << "Remote control mode is " << (itsMyControlMode ? "interactive." : "normal.") << std::endl;
}