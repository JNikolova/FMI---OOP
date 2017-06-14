#ifndef _SHAPE_HEADER_INCLUDED_
#define _SHAPE_HEADER_INCLUDED_

#include <iostream>

class Shape
{
public:
	virtual ~Shape(){};
	virtual Shape* clone() const = 0;
	virtual double area() const = 0;
	virtual double perimeter() const = 0;
	virtual void print() const = 0;

protected: 
	static const double precision;
};


#endif // _SHAPE_HEADER_INCLUDED_