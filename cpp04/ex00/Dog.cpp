#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
	return ;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	return ;
}

Dog::Dog(Dog const &src)
{
	this->_type = src.getType();
	std::cout << "Dog copy constructor called" << std::endl;
	return ;
}

Dog & Dog::operator=(Dog const &rv)
{
	this->_type = rv.getType();
	std::cout << "Dog assignment operator called" << std::endl;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
	return ;
}