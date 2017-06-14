#ifndef _CIRCLE_HEADER_INCLUDED_
#define _CIRCLE_HEADER_INCLUDED_

#include "Shape.h"

class Circle : public Shape
{
public:
	Circle(double);
	
public:
	void set_radius(double);
	double get_radius() const;

public:
	Shape* clone() const;
	double area() const;
	double perimeter() const;
	void print() const;

private:
	static const double pi;
	double radius;
};

#endif //_CIRCLE_HEADER_INCLUDED_