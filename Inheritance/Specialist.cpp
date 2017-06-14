#include "Specialist.h"

Specialist::Specialist(const char* name, const char* addr,const char* egn, 
			const char* depart, double salary, const char* descr):
Employee(name, addr, egn, depart, salary), description(NULL)
{
	set_descr(descr);
}
Specialist::Specialist(const Employee& empl, const char* descr): Employee(empl.get_name(),
																		  empl.get_addr(),
																		  empl.get_egn(),
																		  empl.get_department(),
																		  empl.get_salary()),
																	description(NULL)
{
	set_descr(descr);
}

Specialist::~Specialist()
{
	delete[] description;
}

void Specialist::print() const
{
	std::cout << *this;
}

void Specialist::set_descr(const char* descr)
{
	set(this->description, descr);
}

const char* Specialist::get_descr() const
{
	return description;
}