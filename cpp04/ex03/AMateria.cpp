#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "colours.hpp"

AMateria::AMateria(std::string const & type)
{
	this->_type = type; 
}

AMateria::AMateria()
{
	std::cout << CONSTR_CLR "AMateria default constructor called" END_CLR << std::endl;
	return ;
}

AMateria::~AMateria()
{
	std::cout << DESTR_CLR "AMateria destructor called" END_CLR << std::endl;
	return ;
}

AMateria::AMateria(AMateria const &src)
{
	std::cout << CPY_CONSTR_CLR "AMateria Copy Constructor called" END_CLR << std::endl;
	this->_type = src.getType();
	return ;
}

AMateria & AMateria::operator=(AMateria const &rv)
{
	this->_type = rv.getType();
	return (*this);
}

std::string const & AMateria::getType() const
{
	return(this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* AMateria was USEd on " << target.getName() << " *" << std::endl;
	return ;
}