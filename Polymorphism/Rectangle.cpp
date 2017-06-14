#include "Rectangle.h"

Rectangle::Rectangle(double a, double b)
{
	set_first_side(a);
	set_second_side(b);
}
	
void Rectangle::set_first_side(double fs)
{
	if(fs <= Shape::precision)
	{
		throw std::exception("Try to set negative value of rectangle first side");
	}
	a = fs;
}

void Rectangle::set_second_side(double ss)
{
	if(ss <= Shape::precision)
	{
		throw std::exception("Try to set negative value of rectangle second side");
	}
	b = ss;
}

double Rectangle::get_first_side() const
{
	return a;
}

double Rectangle::get_second_side() const
{
	return b;
}

Shape* Rectangle::clone() const
{
	return new Rectangle(*this);
}

double Rectangle::area() const
{
	return a*b;
}

double Rectangle::perimeter() const
{
	return 2*a + 2*b;
}

void Rectangle::print() const
{
	std::cout << "Rectangle:\nfirst side: " << a << "\nsecond side: " << b << std::endl;
}