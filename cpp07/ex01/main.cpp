#include "iter.hpp"
#include <iostream>

// class Test
// {
// public:
// 	Test(int n): _n(n) {}
// 	int get(void) const {return this->_n;}
// 	Test &operator+(int const &rv) {this->_n += rv; return (*this);}
// 	Test &operator=(Test const &rv) {this->_n = rv.get(); return (*this);}
// private:
// 	int _n;
// };
// std::ostream &operator<<(std::ostream & o, Test const &rv)
// {
// 	o << rv.get();
// 	return o;
// }

template<typename T>
void AddOne (T & x)
{
	x = x + 1;
	std::cout << x << " ";
}

template<typename T>
void AddC (T &x)
{
	x = x + 'c'; //c = 99 in ascii
	std::cout << x << " ";
}

int main( void )
{
	int arrInt[] = {0, 1, 2};
	float arrFloat[] = {0.5, 1.5, 2.5};
	char arrChar[] = {'a', 'b', 'c'};
	std::string arrStr[] = {"lol", "kek", "123"};
	// Test arrTest[] = {Test(20), Test(21), Test(22)};

	iter(arrInt, 3, AddOne);
	std::cout << std::endl;
	iter(arrInt, 3, AddC);
	std::cout << std::endl;

	iter(arrFloat, 3, AddOne);
	std::cout << std::endl;
	iter(arrChar, 3, AddOne);
	std::cout << std::endl;
	iter(arrChar, 3, AddOne);
	std::cout << std::endl;
	iter(arrStr, 3, AddC);
	std::cout << std::endl;

	// iter(arrTest, 3, AddOne);
	// std::cout << std::endl;
	// iter(arrTest, 3, AddOne);
	// std::cout << std::endl;
	return 0;
}

