#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->_type = "WrongCat";
	return ;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
	return ;
}

WrongCat::WrongCat(WrongCat const &src)
{
	this->_type = src.getType();
	std::cout << "WrongCat copy constructor called" << std::endl;
	return ;
}

WrongCat & WrongCat::operator=(WrongCat const &rv)
{
	this->_type = rv.getType();
	std::cout << "WrongCat assignment operator called" << std::endl;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
	return ;
}