#ifndef _SPECIALIST_HEADER_INCLUDED_
#define _SPECIALIST_HEADER_INCLUDED_
#include "Employee.h"

class Specialist: public Employee
{
public:
	Specialist(const char* name, const char* addr,const char* egn, 
				const char* depart, double salary, const char* descr);
	Specialist(const Employee&, const char*);
	virtual ~Specialist();

public:
	void set_descr(const char*);
	const char* get_descr() const;
	virtual void print() const;

private:
	Specialist(const Specialist&);
	Specialist& operator=(const Specialist&);

private:
	char* description;
};

static std::ostream&  operator<<(std::ostream& os, const Specialist& spec)
{
	os << (Employee&) spec << std::endl << spec.get_descr();
	return os;
}

#endif