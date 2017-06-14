#include "Employee.h"


Employee::Employee(const char* name, const char* addr,const char* egn, 
				   const char* depart, double salary):
				name(NULL), addr(NULL), depart(NULL)
{
	try
	{
		set_name(name);
		set_addr(addr);
		set_egn(egn);
		set_department(depart);
		set_salary(salary);
	}
	catch(std::bad_alloc&)
	{
		clean();
		throw;
	}
}

Employee::~Employee()
{
	clean();
}

void Employee::print() const
{
	std::cout << *this;
}

const char* Employee::get_name() const
{
	return name;
}

const char* Employee::get_addr() const
{
	return addr;
}

const char* Employee::get_egn() const
{
	return egn;
}

const char* Employee::get_department() const
{
	return depart;
}

double Employee::get_salary() const
{
	return salary;
}

void Employee::set_name(const char* name)
{
	set(this->name, name);
}

void Employee::set_addr(const char* addr)
{
	set(this->addr, addr);
}

void Employee::set_egn(const char* egn)
{
	int cnt = 0;
	while(egn[cnt] != '\0' && (egn[cnt] >= '0' && egn[cnt] <= '9'))
	{
		++cnt;
	}
	if(cnt != size_egn)
		throw std::exception("Wrong egn\n");
	strcpy(this->egn, egn);
	//strncpy(this->egn, egn, cnt + 1);
}

void Employee::set_department(const char* depart)
{
	set(this->depart, depart);
}

void Employee::set_salary(double salary)
{
	if(salary < 0)
	{
		throw std::exception("Wrong salary\n"); // return;
	}
	this->salary = salary;
}

void Employee::set(char*& dest, const char* src)
{
	int len = strlen(src);
	char* buffer = new char[len + 1];
	strcpy(buffer, src);
	//strncpy(buffer, src, len + 1);
	delete[] dest;
	dest = buffer;
}

void Employee::clean()
{
	delete[] name;
	delete[] addr;
	delete[] depart;
}