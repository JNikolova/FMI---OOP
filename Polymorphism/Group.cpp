#include "Group.h"

Group::Group():shapes(NULL), m_capacity(0), m_size(0)
{}

Group::Group(const Group& rhs)
{
	copy(rhs);
}

Group& Group::operator=(const Group& rhs)
{
	if(this != &rhs)
	{
		clean();
		copy(rhs);
	}

	return *this;
}

Group::~Group()
{
	clean();
}

void Group::add_shape(const Shape* shape)
{
	if(m_size == m_capacity)
	{
		resize(m_capacity ? m_capacity*2 : 2);
	}
	shapes[m_size++] = shape->clone();
}

void Group::print() const
{
	std::cout << "Group:\n";
	for(size_t i = 0; i < m_size; ++i)
	{
		shapes[i]->print();
	}
}

void Group::resize(size_t newCapacity)
{
	Shape** buffer = new Shape*[newCapacity];
	copy(buffer,shapes, m_size);
	clean();
	shapes = buffer;
	m_capacity = newCapacity;
}

void Group::copy(Shape** dest, Shape**const  src, size_t size)
{
	for(int i = 0; i < size; ++i)
	{
		dest[i] = src[i]->clone();
	}
}

void Group::copy(const Group& rhs)
{
	resize(rhs.m_size);
	copy(shapes, rhs.shapes, rhs.m_size);
	m_size = rhs.m_size;
}

void Group::clean()
{
	while(m_size)
	{
		delete shapes[--m_size];
	}

	delete[] shapes;
}
