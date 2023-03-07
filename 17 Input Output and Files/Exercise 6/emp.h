// emp.h -- header file for abstr_emp class and children
#include <iostream>
#include <string>
#include<fstream>

using std::fstream;

class abstr_emp
{
protected:
	std::string fname; // abstr_emp's first name
	std::string lname; // abstr_emp's last name
	std::string job;
public:
	abstr_emp();
	abstr_emp(const std::string & fn, const std::string & ln,
		const std::string & j);
	virtual void ShowAll() const; // labels and shows all data
	virtual void SetAll(); // prompts user for values
	friend std::ostream & operator<<(std::ostream & os, const abstr_emp & e);
	// just displays first and last name
	virtual ~abstr_emp() {} // virtual base class
	virtual void writeall(fstream&) {}
	virtual void getall(fstream&) {}
};
class employee : public abstr_emp
{
public:
	employee();
	employee(const std::string & fn, const std::string & ln,
		const std::string & j);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void writeall(fstream&);
	virtual void getall(fstream&);
};
class manager : virtual public abstr_emp
{
protected:
	int inchargeof; // number of abstr_emps managed
	int InChargeOf() const { return inchargeof; } // output
	int & InChargeOf() { return inchargeof; } // input
public:
	manager();
	manager(const std::string & fn, const std::string & ln,
		const std::string & j, int ico = 0);
	manager(const abstr_emp & e, int ico);
	manager(const manager & m);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void writeall(fstream&);
	virtual void getall(fstream&);
};
class fink : virtual public abstr_emp
{
protected:
	std::string reportsto; // to whom fink reports
	const std::string ReportsTo() const { return reportsto; }
	std::string & ReportsTo() { return reportsto; }
public:
	fink();
	fink(const std::string & fn, const std::string & ln,
		const std::string & j, const std::string & rpo);
	fink(const abstr_emp & e, const std::string & rpo);
	fink(const fink & e);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void writeall(fstream&);
	virtual void getall(fstream&);
};
class highfink : public manager, public fink // management fink
{
public:
	highfink();
	highfink(const std::string & fn, const std::string & ln,
		const std::string & j, const std::string & rpo,
		int ico);
	highfink(const abstr_emp & e, const std::string & rpo, int ico);
	highfink(const fink & f, int ico);
	highfink(const manager & m, const std::string & rpo);
	highfink(const highfink & h);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void writeall(fstream&);
	virtual void getall(fstream&);
};