#include "Manager.h"

Manager::Manager(const char* name, const char* addr,const char* egn, 
				const char* depart, double salary, const char* descr,const char* depart_inf):
Specialist(name, addr, egn, depart, salary, descr), depart_inf(NULL)
{
	set_depart_info(depart_inf);
}


Manager::Manager(const Specialist& spec, const char* depart_inf):
	Specialist(spec.get_name(), spec.get_addr(), spec.get_egn(), spec.get_department(), 
				spec.get_salary(), spec.get_descr()), depart_inf(NULL)
{
	set_depart_info(depart_inf);
}

Manager::~Manager()
{
	delete[] depart_inf;
}

const char* Manager::get_depart_info() const
{
	return depart_inf;
}

void Manager::set_depart_info(const char* depart_inf)
{
	set(this->depart_inf, depart_inf);
}

void Manager::print() const
{
	Specialist::print();
	std::cout << get_depart_info() << std::endl << "Employees:\n";
	employees.print();
}

void Manager::add_employee(const Employee* empl)
{
	if(!strcmp(get_department(), empl->get_department()))
	{
		employees.add(empl);
	}
}

void Manager::remove_employee(const Employee* empl)
{
	employees.remove(empl);
}