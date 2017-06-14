#ifndef _SECRETARY_HEADER_INCLUDED_
#define _SECRETARY_HEADER_INCLUDED_

#include "Employee.h"

class Secretary: public Employee
{
public:
	Secretary(const char* name, const char* addr,const char* egn, const char* depart, double salary, const char** languages = NULL, int cnt = 0);
	Secretary(const Employee&, const char** languages = NULL, int cnt = 0);
	virtual ~Secretary();

public:
	void add_language(const char*);
	virtual void print() const;
	
private:
	void resize(int);
	void add_languages(const char**, int);
	static void copy(const char** dest, const char** src, int size);

private:
	Secretary(const Secretary&);
	Secretary& operator=(const Secretary&);

private:
	const char** languages;
	int size;
	int capacity;
};

#endif