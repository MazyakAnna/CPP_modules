#include "Brain.hpp"
#include "colours.hpp" 

Brain::Brain()
{
	std::cout << CONSTR_CLR "Brain appeared!" END_CLR << std::endl;
	return ;
}

Brain::~Brain()
{
	std::cout << DESTR_CLR "Brain destructor called" END_CLR << std::endl;
	return ;
}

Brain::Brain(Brain const &src)
{
	for (int i = 0; i < 100; i++)
		this->setIdea(src.getIdea(i), i);
	std::cout << CPY_CONSTR_CLR "Brain copy constructor called" END_CLR << std::endl;
	return ;
}

Brain & Brain::operator=(Brain const &rv)
{
	for (int i = 0; i < 100; i++)
		this->setIdea(rv.getIdea(i), i);
	std::cout << ASSIGN_CLR "Brain assignment operator called" END_CLR << std::endl;
	return (*this);
}

std::string	Brain::getIdea(unsigned int i) const
{
	if (i < 100)
		return (this->ideas[i]);
	else
	{
		std::cout << "idea index out of boundaries, index = 0" << std::endl;
		return (this->ideas[0]);
	}
}

void	Brain::setIdea(std::string idea, int i)
{
	this->ideas[i] = idea;
	return ;
}

void	Brain::setIdeas(std::string idea)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = idea;
	return ;
}