#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
	return ;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	return ;
}

Cat::Cat(Cat const &src)
{
	this->_type = src.getType();
	std::cout << "Cat copy constructor called" << std::endl;
	return ;
}

Cat & Cat::operator=(Cat const &rv)
{
	this->_type = rv.getType();
	std::cout << "Cat assignment operator called" << std::endl;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
	return ;
}