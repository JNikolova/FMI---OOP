#ifndef _EMPLOYEES_HEADER_INCLUDED_
#define _EMPLOYEES_HEADER_INCLUDED_

#include "Employee.h"

class Employees
{
public:
	Employees();
	Employees(const Employees&);
	Employees& operator=(const Employees&);
	~Employees();

public:
	void add(const Employee*);
	void remove(const Employee*);
	size_t size() const;
	const Employee& operator[](int) const;
	void print() const;
	

private:
	void resize(int);
	void copy(const Employees&);
	int isAdded(const Employee*);
	void clean();

private:
	const Employee** empl;
	size_t m_size;
	size_t m_capacity;
};

#endif