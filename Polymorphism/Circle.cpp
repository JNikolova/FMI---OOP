#include "Circle.h"

const double Circle::pi = 3.14;

Circle::Circle(double r)
{
	set_radius(r);
}

void Circle::set_radius(double r)
{
	if(r <= Shape::precision)
	{
		throw std::exception("Try to set negative value of radius");
	}
	radius = r;
}

double Circle::get_radius() const
{
	return radius;
}

Shape* Circle::clone() const
{
	return new Circle(*this);
}

double Circle::perimeter() const
{
	return 2*pi*radius;
}

double Circle::area() const
{
	return pi*radius*radius;
}

void Circle::print() const
{
	std::cout << "Circle:\nradius: " << radius << std::endl;
}