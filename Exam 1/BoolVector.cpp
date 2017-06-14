#include "BoolVector.h"

const short BoolVector::alignment = 32;

BoolVector::BoolVector(): vec(NULL), size(0)
{}

BoolVector::BoolVector(int size): vec(NULL), size(0)
{
	resize(size);
}

BoolVector::BoolVector(const BoolVector& rhs): vec(NULL), size(0)
{
	vec = new int[rhs.size];
	copy(vec,rhs.vec, rhs.size);
	size = rhs.size;
}

BoolVector& BoolVector::operator=(const BoolVector& rhs)
{
	if(this != &rhs)
	{
		int* buffer = new int[rhs.size];
		copy(buffer,rhs.vec, rhs.size);
		clean();
		vec = buffer;
		size = rhs.size;
	}
	return *this;
}

BoolVector::~BoolVector()
{
	clean();
}

bool BoolVector::set(int i)
{
	if(size*alignment <= i || i < 0)
		return false;
	size_t box = i/alignment;
	size_t index = i%alignment;

	vec[box] |= 1 << (alignment - index - 1);
}

bool BoolVector::clear(int i)
{
	if(size*alignment <= i || i < 0)
		return false;
	size_t box = i/alignment;
	size_t index = i%alignment;

	vec[box] &= ~(1 << (alignment - index - 1));
}

bool BoolVector::flip(int i)
{
	if(size*alignment <= i || i < 0)
		return false;
	size_t box = i/alignment;
	size_t index = i%alignment;

	vec[box] ^= vec[box] & (1 << (alignment - index - 1));
}

short BoolVector::operator[](int i) const
{
	if(size*alignment <= i || i < 0)
		return -1;
	size_t box = i/alignment;
	size_t index = i%alignment;

	return vec[box] & (1 << (alignment - index - 1)) ? 1 : 0;
}

BoolVector& BoolVector::operator&=(const BoolVector& rhs)
{
	if(size < rhs.size)
		resize(rhs.size*alignment);
	for(int i = 0; i < rhs.size; ++i)
		vec[i] &= rhs.vec[i];
	for(int i = rhs.size; i < size; ++i)
		vec[i] = 0;
	return *this;
}

BoolVector BoolVector::operator&(const BoolVector& rhs) const
{
	BoolVector result = *this;
	result &= rhs;
	return result;
}

BoolVector& BoolVector::operator|=(const BoolVector& rhs)
{
	if(size < rhs.size)
		resize(rhs.size*alignment);
	for(int i = 0; i < rhs.size; ++i)
		vec[i] |= rhs.vec[i];
	return *this;
}

BoolVector BoolVector::operator|(const BoolVector& rhs) const
{
	BoolVector result(*this);
	result |= rhs;
	return result;
}

BoolVector BoolVector::operator^(const BoolVector& rhs) const
{
	BoolVector result(*this);
	result ^= rhs;
	return result;
}

BoolVector& BoolVector::operator^=(const BoolVector& rhs)
{
	if(size < rhs.size)
		resize(rhs.size*alignment);
	for(int i = 0; i < rhs.size; ++i)
		vec[i] ^= rhs.vec[i];
	for(int i = rhs.size; i < size; ++i)
		vec[i] ^= 0;
	return *this;
}

BoolVector::operator bool() const
{
	short isFind = 0;
	for(int i =0; i < size; ++i)
	{
		if(vec[i] & (vec[i] - 1))
		{
			if(vec[i])
				return false;
		}
		else
		{
			if(vec[i])
				++isFind;
		}
	}
	return isFind <= 1;
}

void BoolVector::resize(int newSize)
{
	if(newSize < 0 )
		throw std::bad_alloc();
	if(newSize%alignment != 0)
		throw std::exception("Size is not alignment\n");
	if(newSize < size)
		throw std::exception("Try to make down resize");
	newSize = newSize / alignment;
	int* buffer = new int[newSize];
	copy(buffer, vec, size);
	for(int i = size; i < newSize; ++i)
		buffer[i] = 0;
	delete[] vec;
	vec = buffer;
	size = newSize;
}

void BoolVector::copy(int* desk, const int* src, size_t size)
{
	for(int i = 0; i < size; ++i)
		desk[i] = src[i];
}

void BoolVector::clean()
{
	delete[] vec;
	vec = NULL;
	vec = 0;
	size = 0;
}

size_t BoolVector::getSize() const
{
	return size*alignment;
}

std::ostream& operator<<(std::ostream& os, const BoolVector& obj)
{
	for(int i = 0; i < obj.size; ++i)
	{
		for(unsigned mask = 1 << (BoolVector::alignment - 1); mask ; mask >>= 1)
		{
			os << (mask & obj.vec[i] ? '1' : '0');
		}
	}
	return os;
}