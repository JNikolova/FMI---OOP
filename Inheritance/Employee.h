#ifndef _EMPLOYEE_HEADER_INCLUDED_
#define _EMPLOYEE_HEADER_INCLUDED_

#include <iostream>

class Employee
{
public:
	Employee(const char* name, const char* addr,const char* egn, const char* depart, double salary);
	virtual ~Employee();

public:
	const char* get_name() const;
	const char* get_addr() const;
	const char* get_egn() const;
	const char* get_department() const;
	double get_salary() const;

	void set_name(const char* );
	void set_addr(const char*);
	void set_egn(const char*);
	void set_department(const char*);
	void set_salary(double);
	virtual void print() const;

protected:
	static void set(char*& , const char*);
	void clean();

private:
	Employee(const Employee&);
	Employee& operator=(const Employee&);

private:
	static const int size_egn = 10;
	char* name;
	char* addr;
	char egn[size_egn + 1];
	char* depart;
	double salary;
};

static std::ostream& operator<<(std::ostream& os, const Employee& employee)
{
	 os << employee.get_name() << std::endl
		<< employee.get_addr() << std::endl
		<< employee.get_egn() << std::endl
		<< employee.get_department() << std::endl
		<< employee.get_salary();

	return os;
}

#endif