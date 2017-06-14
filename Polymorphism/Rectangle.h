#ifndef _RECTANGLE_HEADER_INCLUDED_
#define _RECTANGLE_HEADER_INCLUDED_

#include "Shape.h"

class Rectangle: public Shape
{
public:
	Rectangle(double a, double b);
	
public:
	void set_first_side(double a);
	void set_second_side(double b);
	double get_first_side() const;
	double get_second_side() const;

public:
	Shape* clone() const;
	double area() const;
	double perimeter() const;
	void print() const;

private:
	double a,b;
};

#endif //_RECTANGLE_HEADER_INCLUDED_