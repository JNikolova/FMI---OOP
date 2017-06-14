#ifndef _BOOL_VECTOR_HEADER_INCLUDED_
#define _BOOL_VECTOR_HEADER_INCLUDED_

#include <iostream>

class BoolVector
{
public:
	BoolVector();
	explicit BoolVector(int size);
	BoolVector(const BoolVector& rhs);
	BoolVector& operator=(const BoolVector& rhs);
	~BoolVector();

public:
	bool set(int i);
	bool clear(int i);
	bool flip(int i);

public:
	void resize(int newSize);
	size_t getSize() const;

public:
	short operator[](int i) const;
	BoolVector& operator&=(const BoolVector& rhs);
	BoolVector operator&(const BoolVector& rhs) const;
	BoolVector& operator|=(const BoolVector& rhs);
	BoolVector operator|(const BoolVector& rhs) const;
	BoolVector operator^(const BoolVector& rhs) const;
	BoolVector& operator^=(const BoolVector& rhs);
	operator bool() const;
	friend std::ostream& operator<<(std::ostream& os, const BoolVector& obj);

private:
	static void copy(int* desk, const int* src, size_t size);
	void clean();

private:
	int* vec;
	size_t size;
	static const short alignment;
};


#endif