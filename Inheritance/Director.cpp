#include "Director.h"

Director::Director(const char* name, const char* addr,const char* egn, const char* depart, 
					double salary, const Secretary* secretary,const Employees& empl_s):
Employee(name, addr, egn, depart, salary), empl_s(empl_s), m_secretary(secretary)
{
	this->empl_s.add(secretary);
}

Director::Director(const Employee& empl, const Secretary* secretary,const Employees& empl_s):
	Employee(empl.get_name() , empl.get_addr(), empl.get_egn(), empl.get_department(),
	empl.get_salary()), empl_s(empl_s), m_secretary(secretary)
{
	this->empl_s.add(secretary);
}

void Director::add_employee(const Employee* empl)
{
	empl_s.add(empl);
}

void Director::remove_employee(const Employee* empl)
{
	empl_s.remove(empl);
}

void Director::change_secretary(const Secretary* secretary)
{
	m_secretary = secretary;
	remove_employee(secretary);
	add_employee(secretary);
}

void Director::print() const
{
	Employee::print();
	std::cout << "Secretary:\n";
	m_secretary->print();
	std::cout << "Employees:\n";
	empl_s.print();
}