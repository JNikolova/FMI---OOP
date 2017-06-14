#include "Secretary.h"

Secretary::Secretary(const char* name, const char* addr,const char* egn, const char* depart, double salary, 
					 const char** languages, int cnt):
Employee(name, addr, egn, depart, salary), languages(NULL), size(0), capacity(0)
{
	add_languages(languages, cnt);
}
	
Secretary::Secretary(const Employee& empl, const char** languages, int cnt):
	Employee(empl.get_name(), empl.get_addr(), empl.get_egn(), empl.get_department(), empl.get_salary()), 
	languages(NULL), size(0), capacity(0)
{
	add_languages(languages, cnt);
}

Secretary::~Secretary()
{
	delete[] languages;
}

void Secretary::add_language(const char* language)
{
	if(size == capacity)
	{
		resize(capacity ? 2*capacity : 2);
	}

	languages[size++] = language;
}

void Secretary::print() const
{
	Employee::print();
	std::cout << "\nLanguages:\n";
	for(int i = 0; i < size; ++i)
	{
		std::cout  << languages[i] << std::endl;
	}
}

void Secretary::resize(int newSize)
{
	if(newSize < size)
		return;
	const char** buffer = new const char*[newSize];
	copy(buffer, languages, size);
	delete[] languages;
	languages = buffer;
	capacity = newSize;
}

void Secretary::add_languages(const char** lang_s, int cnt)
{
	if(cnt <= 0)
		return;
	//int newCapacity = capacity + cnt;
	//const char** buffer = new const char*[newCapacity];
	//copy(buffer, languages, size);
	//delete[] languages;
	//languages = buffer
	languages = new const char*[cnt];
	copy(languages, lang_s, cnt);
	size = cnt;
	capacity = size;
	//size += cnt;
	//capacity = newCapacity;
}

void Secretary::copy(const char** dest, const char** src, int size)
 {
	 for(int i = 0; i < size; ++i)
	 {
		 dest[i] = src[i];
	 }
 }