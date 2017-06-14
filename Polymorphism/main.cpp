#include <iostream>
#include "Group.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"

int main()
{
	Group gr;
	Rectangle rec(5,4);
	gr.add_shape(rec);
	gr.print();
}