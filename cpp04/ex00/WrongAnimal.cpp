#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("Wrong_animal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	this->_type = src.getType();
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	return ;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const &rv)
{
	this->_type = rv.getType();
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (this->_type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Unknown Wrong_Animal Sound..." << std::endl;
	return ;
}
