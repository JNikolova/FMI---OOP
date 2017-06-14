#ifndef _DIRECTOR_HEADER_INCLUDED_
#define _DIRECTOR_HEADER_INCLUDED_

#include "Employee.h"
#include "Employees.h"
#include "Secretary.h"

class Director: public Employee
{
public:
	Director(const char* name, const char* addr,const char* egn, const char* depart, 
					double salary, const Secretary* ,const Employees&);
	Director(const Employee&, const Secretary* ,const Employees&);

public:
	void add_employee(const Employee*);
	void remove_employee(const Employee*);
	void change_secretary(const Secretary*);
	virtual void print() const;

private:
	Director(const Director&);
	Director& operator=(const Director&);

private:
	const Secretary* m_secretary;
	Employees empl_s;
};


#endif