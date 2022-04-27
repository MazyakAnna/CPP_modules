#include "Cat.hpp"
#include "colours.hpp" 

Cat::Cat() : Animal()
{
	std::cout << CONSTR_CLR "Cat default constructor called" END_CLR << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
	this->_brain->setIdeas("FISH");
	std::cout << "Cat's ideas = FISH" << std::endl;
	return ;
}

Cat::~Cat()
{
	std::cout << DESTR_CLR "Cat destructor called" END_CLR << std::endl;
	delete(this->_brain);
	return ;
}

Cat::Cat(Cat const &src)
{
	this->_type = src.getType();
	this->_brain = new Brain (*src._brain);
	std::cout << CPY_CONSTR_CLR "Cat copy constructor called" END_CLR << std::endl;
	return ;
}

Cat & Cat::operator=(Cat const &rv)
{
	this->_type = rv.getType();
	for (int i = 0; i < 100; i++)
		this->_brain->setIdea(rv.getBrain()->getIdea(i), i);
	std::cout << ASSIGN_CLR "Cat assignment operator called" END_CLR << std::endl;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
	return ;
}

const Brain* Cat::getBrain() const
{
	return (this->_brain);
}

void Cat::kickCat()
{
	std::cout << "Cat was kicked!" << std::endl;
	this->_brain->setIdea("HATE", 0);
}