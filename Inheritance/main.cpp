#include "Employee.h"
#include "Specialist.h"
#include "Employees.h"
#include "Manager.h"
#include "Secretary.h"
#include "Director.h"

void test()
{
	Employee emp("Yoanna", "csakjkj", "0123456789", "FMI", 1.20);
	emp.set_name("Maria");
	emp.set_addr("asdfg");
	emp.set_egn("9874641230");
	emp.set_department("infdjkkhfdsjh");
	emp.set_salary(123);
	//std::cout << emp << std::endl;
	Specialist sp(emp, "jjhdgsj");
	sp.set_name("Ivan");
	//std::cout << sp << std::endl;
	Employees empl_s;
	empl_s.add(&emp);
	empl_s.add(&sp);
	//empl_s.print();
	Manager theMan(sp, "information");
	theMan.add_employee(&emp);
	theMan.add_employee(&sp);
	empl_s.add(&theMan);
	//theMan.print();
	theMan.remove_employee(&sp);
	//theMan.print();
	Secretary sec(emp);
	empl_s.add(&sec);
	sec.add_language("sdkahfsd");
	sec.add_language("safsa");
	//sec.print();
	//empl_s.print();
	Director dir(emp, &sec ,empl_s);
	dir.print();

}

int main()
{
	try{
		test();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

}