#include <iostream>
#include "BoolVector.h"

int main()
{
	BoolVector v(64);
	BoolVector v1(32);
	BoolVector v5;
	v.set(3);
	BoolVector v2(v);
	v.set(63);
	BoolVector v3(v);
	for(int i = 0; i < 32; i+=2)
		v1.set(i);
	try
	{
		BoolVector v4(52);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "v : " <<  v  << std::endl;
	std::cout << "v1 : " << v1 << std::endl;
	std::cout << "& : " << (v & v1) << std::endl;
	std::cout << "| : " << (v | v1) << std::endl;
	std::cout << "^ : " << (v ^ v1) << std::endl;
	std::cout << "&= : " << (v &= v1) << std::endl;
	std::cout << "|= : " << (v |= v1) << std::endl;
	std::cout << "^= : " << (v ^= v2) << std::endl;
	std::cout << "v : " <<  v  << std::endl;
	std::cout << "v1 : " << v1 << std::endl;
	std::cout << "bool v : " << (bool)v << std::endl;
	std::cout << "bool v1 : " << (bool)v1 << std::endl;
	std::cout << "bool v2 : " << (bool)v2 << std::endl;
	std::cout << v.getSize() << std::endl;
	std::cout << "v3 : " << v3 << std::endl;
	std::cout << "v3[62] : " << v3[62] <<std::endl;
	std::cout << "v3[63] : " << v3[63] <<std::endl;
	std::cout << "v3[64] : " << v3[64] <<std::endl;
	v3.set(32);
	std::cout << "v3 : " << v3 << std::endl;
	std::cout << "v3[32] : " << v3[32] << std::endl; 
}