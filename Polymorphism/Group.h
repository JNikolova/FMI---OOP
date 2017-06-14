#ifndef _GROUP_HEADER_INCUDED_
#define _GROUP_HEADER_INCUDED_

#include "Shape.h"

class Group
{
public:
	Group();
	Group(const Group&);
	Group& operator=(const Group&);
	~Group();

public:
	void add_shape(const Shape&);
	void print() const;

private:
	void resize(size_t);
	void copy(const Group&);
	static void copy(Shape**, Shape** const , size_t);
	void clean();

private:
	Shape** shapes;
	size_t m_size;
	size_t m_capacity;
};

#endif //_GROUP_HEADER_INCUDED_