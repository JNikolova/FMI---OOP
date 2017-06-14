#include "Triangle.h"

Triangle::Triangle(double a, double b, double c)
{
	set_sides(a,b,c);
}

	
void Triangle::set_sides(double a, double b, double c)
{
	validation(a, b, c);
	this->a = a;
	this->b = b;
	this->c = c;
}

double Triangle::get_a() const
{
	return a;
}

double Triangle::get_b() const
{
	return b;
}

double Triangle::get_c() const
{
	return c;
}

Shape* Triangle::clone() const
{
	return new Triangle(*this);
}

double Triangle::perimeter() const
{
	return a + b + c;
}

double Triangle::area() const
{
	const double p = (a + b + c);
	return sqrt(p*(p - a)*(p - b)*(p - c));
}

void Triangle::print() const
{
	std::cout << "Triangle:\na : " << a << "\nb : " << b << "\nc : " << c << std::endl;
}

void Triangle::validation(double a, double b, double c)
{
	const bool check1 = (a + b) - c > Shape::precision;
	const bool check2 = (a + c) - b > Shape::precision;
	const bool check3 = (c + b) - a > Shape::precision;

	if(a < Shape::precision || b < Shape::precision || c < Shape::precision ||
				!check1 || !check2 || !check3)
	{
		throw std::exception("Invalid triangle sides");
	}
}