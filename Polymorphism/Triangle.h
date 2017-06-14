#ifndef _TRIANGLE_HEADER_INCLUDED_
#define _TRIANGLE_HEADER_INCLUDED_

#include "Shape.h"

class Triangle :public Shape
{
public:
	Triangle(double a, double b, double c);
	
public:
	void set_sides(double a, double b, double c);
	double get_a() const;
	double get_b() const;
	double get_c() const;

public:
	Shape* clone() const;
	double area() const;
	double perimeter() const;
	void print() const;

private:
	static void validation(double, double, double);

private:
	double a, b, c;
};

#endif // _TRIANGLE_HEADER_INCLUDED_