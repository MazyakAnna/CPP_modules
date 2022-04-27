#include "Dog.hpp"
#include "colours.hpp"

Dog::Dog() : Animal()
{
	std::cout << CONSTR_CLR "Dog default constructor called" END_CLR << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
	this->_brain->setIdeas("BONE");
	std::cout << "Dog's ideas = BONE" << std::endl;
	return ;
}

Dog::~Dog()
{
	std::cout << DESTR_CLR "Dog destructor called" END_CLR << std::endl;
	delete(this->_brain);
	return ;
}

Dog::Dog(Dog const &src)
{
	this->_type = src.getType();
	this->_brain = new Brain(*src.getBrain());
	std::cout << CPY_CONSTR_CLR "Dog copy constructor called" END_CLR << std::endl;
	return ;
}

Dog & Dog::operator=(Dog const &rv)
{
	this->_type = rv.getType();
	for (int i = 0; i < 100; i++)
		this->_brain->setIdea(rv.getBrain()->getIdea(i), i);
	std::cout << ASSIGN_CLR "Dog assignment operator called" END_CLR << std::endl;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
	return ;
}

const Brain*	Dog::getBrain() const
{
	return (this->_brain);
}