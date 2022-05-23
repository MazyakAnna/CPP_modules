#include "serial.hpp"
# include <iostream>

//It takes a pointer and converts it to the unsigned integer type uintptr_t
uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

//It takes an unsigned integer parameter and converts it to a pointer to Data.
Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main()
{
	Data data;
	uintptr_t int_ptr;
	Data *data_ptr;

	data.lol = 5;
	data.kek = 3.1415;

	int_ptr = serialize(&data);
	data_ptr = deserialize(int_ptr);
	std::cout << data_ptr << " vs. " << &data << std::endl;
	std::cout << data_ptr << " in hex == " << int_ptr << " in dec" << std::endl;
	std::cout << data_ptr->lol << " -- " << data_ptr->kek << std::endl;

	return (0);
}

