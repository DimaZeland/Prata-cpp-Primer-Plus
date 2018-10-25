// dma.h  -- inheritance and dynamic memory allocation
#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class AbstractDMA { // abstract base class
private:
	char * label;
	int rating;
public:
	AbstractDMA(const char * l = "null", int r = 0); // explicit overload constructor
	AbstractDMA(const AbstractDMA & rs); // explicit copy constructor
	virtual ~AbstractDMA(); // explicit destructor
	virtual AbstractDMA & operator=(const AbstractDMA & rs); // pure virtual function
	friend std::ostream & operator<<(std::ostream & os, const AbstractDMA & rs);
	virtual void View()const = 0;
};

//  Base Class Using DMA
class baseDMA: public AbstractDMA
{
private:
    int score;
public:
    baseDMA(const char * l = "null", int r = 0, int s = 0); // explicit overload constructor
    baseDMA(const baseDMA & rs); // explicit copy constructor
	~baseDMA() {} // explicit destructor
    baseDMA & operator=(const baseDMA & rs); // redefinition of pure virtual function
    friend std::ostream & operator<<(std::ostream & os, const baseDMA & rs);
	void View()const;
};

// derived class without DMA
// no destructor needed
// uses implicit copy constructor
// uses implicit assignment operator
class lacksDMA :public AbstractDMA
{
private:
    enum { COL_LEN = 40};
    char color[COL_LEN];
public:
    lacksDMA(const char * c = "blank", const char * l = "null",
              int r = 0);
    lacksDMA(const char * c, const AbstractDMA & rs);
	lacksDMA & operator=(const lacksDMA & rs); // redefinition of pure virtual function
    friend std::ostream & operator<<(std::ostream & os, const lacksDMA & rs);
	void View()const;
};

// derived class with DMA
class hasDMA :public AbstractDMA
{
private:
    char * style;
public:
    hasDMA(const char * s = "none", const char * l = "null",
              int r = 0);
    hasDMA(const char * s, const AbstractDMA & rs);
    hasDMA(const hasDMA & hs);
    ~hasDMA();
    hasDMA & operator=(const hasDMA & rs);  
    friend std::ostream & operator<<(std::ostream & os, const hasDMA & rs);
	void View()const;
};
#endif
