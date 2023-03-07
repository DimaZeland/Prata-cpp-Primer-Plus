#pragma once

#include <iostream>
#include<string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Person {
private:
	string itsMyFirstName;
	string itsMyLastName;
public:
	// constructors & destructor
	Person(string firstName = "NoFirstName", string lastName = "NoLastName") // overload explicit base constructor
		: itsMyFirstName(firstName), itsMyLastName(lastName) {}
	virtual ~Person(){}
	// class methods
	virtual void Show()const; // output data values of class members
	virtual void Set(); // set the value of class fields
};

class Gunslinger: virtual public Person {
private:
	double itsMyTime;
	int itsMyRifleNotches;
public:
	// constructors & destructor
	Gunslinger(string firstName = "NoFirstName", string lastName = "NoLastName", double time = 0, int Rifle = 0)  // overload explicit base constructor
	: Person(firstName, lastName), itsMyTime(time), itsMyRifleNotches(Rifle) {}
	~Gunslinger() {}
	inline double Draw()const { return itsMyTime; }
	virtual void Show()const; // output data values of class members
	virtual void Set(); // set the value of class fields
};

class PokerPlayer : virtual public Person {
private:

public:
	// constructors & destructor
	PokerPlayer(string firstName = "NoFirstName", string lastName = "NoLastName") // overload explicit base constructor
		:Person(firstName, lastName) {}
	~PokerPlayer(){}
	// class methods
	inline int Draw()const {return rand() % 52 + 1;}
};

class BadDude : public Gunslinger, public PokerPlayer {
private:
	
public:
	// constructors & destructor
	BadDude(string firstName = "NoFirstName", string lastName = "NoLastName", double time = 0, int Rifle = 0) // overload explicit base constructor
		:Person(firstName, lastName), Gunslinger(firstName, lastName, time, Rifle), PokerPlayer(firstName, lastName) {}
	~BadDude() {}
	// class methods
	inline int Gdraw() const{ return rand() % 10 + 1; }
	inline int Cdraw() const { return rand() % 52 + 1; }
	void Show()const;
};