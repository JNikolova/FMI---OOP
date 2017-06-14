#include "Employees.h"

Employees::Employees(): empl(NULL), m_size(0), m_capacity(0)
{}

Employees::~Employees()
{
	clean();
}

Employees::Employees(const Employees& empl_s): empl(NULL), m_size(0), m_capacity(0)
{
	copy(empl_s);
}

Employees& Employees::operator=(const Employees& empl_s)
{
	if(this != &empl_s)
	{
		clean();
		copy(empl_s);
	}

	return *this;
}

void Employees::add(const Employee* obj)
{
	int index = isAdded(obj);
	if(index < 0)
	{
		if(m_size == m_capacity)
		{
			resize(m_capacity ? m_capacity*2 : 2);
		}
		empl[m_size++] = obj;
	}
}

void Employees::remove(const Employee* obj)
{
	int index = isAdded(obj);
	if(index >= 0){
		empl[index] = empl[--m_size];
	}
}

int Employees::isAdded(const Employee* obj)
{
	for(int i = 0; i < m_size; ++i)
	{
		if(empl[i] == obj)
		{
			return i;
		}
	}

	return -1;
}

void Employees::print() const
{
	for(int i = 0; i < m_size; ++i)
	{
		empl[i]->print();
		std::cout << std::endl;
	}
}

size_t Employees::size() const
{
	return m_size;
}

const Employee& Employees::operator[](int index) const
{
	if(index <0 || index >= m_size)
	{
		throw std::out_of_range("Employees::operator[]");
	}
	return *(empl[index]);
}


void Employees::resize(int newCapacity)
{
	const Employee** buffer = new const Employee*[newCapacity];
	for(int i = 0; i < m_size; ++i)
	{
		buffer[i] = empl[i];
	}
	delete[] empl;
	empl = buffer;
	m_capacity = newCapacity;
}

void Employees::copy(const Employees& rhs)
{
	empl = new const Employee*[rhs.m_capacity];
	for(int i = 0; i < rhs.m_size; ++i)
	{
		add(rhs.empl[i]);
	}
	m_size = rhs.m_size;
	m_capacity = rhs.m_capacity;
}

void Employees::clean()
{
	delete[] empl;
	m_size = 0;
	m_capacity = 0;
}