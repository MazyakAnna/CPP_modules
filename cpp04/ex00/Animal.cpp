#include "Animal.hpp"

Animal::Animal(): _type("UnknownAnimal")
{
	std::cout << "Animal default constructor called" << std::endl;
	return ;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
	return ;
}

Animal::Animal(Animal const &src)
{
	this->_type = src.getType();
	std::cout << "Animal copy constructor called" << std::endl;
	return ;
}

Animal & Animal::operator=(Animal const &rv)
{
	this->_type = rv.getType();
	std::cout << "Animal assignment operator called" << std::endl;
	return (*this);
}

std::string Animal::getType() const
{
	return (this->_type);
}

void	Animal::makeSound() const
{
	std::cout << "Unknown Animal Sound..." << std::endl;
	return ;
}
