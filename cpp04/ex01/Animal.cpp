#include "Animal.hpp"
#include "colours.hpp" 

Animal::Animal(): _type("Unknown_animal")
{
	std::cout << CONSTR_CLR "Animal default constructor called" END_CLR << std::endl;
	return ;
}

Animal::~Animal()
{
	std::cout << DESTR_CLR "Animal destructor called" END_CLR << std::endl;
	return ;
}

Animal::Animal(Animal const &src)
{
	this->_type = src.getType();
	std::cout << CPY_CONSTR_CLR "Animal copy constructor called" END_CLR << std::endl;
	return ;
}

Animal & Animal::operator=(Animal const &rv)
{
	this->_type = rv.getType();
	std::cout << ASSIGN_CLR "Animal assignment operator called" END_CLR << std::endl;
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
