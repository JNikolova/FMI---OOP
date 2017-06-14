#ifndef _MANAGER_HEADER_INCLUDED_
#define _MANAGER_HEADER_INCLUDED_

#include "Specialist.h"
#include "Employees.h"

class Manager: public Specialist
{
public:
	Manager(const char* name, const char* addr,const char* egn, 
				const char* depart, double salary, const char* descr,const char* depart_inf);
	Manager(const Specialist&, const char* );
	virtual ~Manager();

public:
	const char* get_depart_info() const;
	void  set_depart_info(const char*);
	virtual void print()  const;
	void add_employee(const Employee* );
	void remove_employee(const Employee* );

private:
	Manager(const Manager&);
	Manager& operator=(const Manager&);

private:
	char* depart_inf;
	Employees employees;
};


#endif