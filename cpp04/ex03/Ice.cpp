#include "Ice.hpp"
#include "ICharacter.hpp"
#include "colours.hpp"

Ice::Ice()
{
    this->_type = "ice";
    std::cout << CONSTR_CLR "Ice Constructor called" END_CLR << std::endl;
    return ;
}

Ice::~Ice()
{
    std::cout << DESTR_CLR "Ice Destructor called" END_CLR << std::endl;
    return ;
}
	
Ice::Ice(Ice const &src)
{
    std::cout << CPY_CONSTR_CLR "Ice Copy Constructor called" END_CLR << std::endl;
    this->_type = src.getType();
    return ;
}

Ice & Ice::operator=(Ice const &rv)
{
    this->_type = rv.getType(); //Subject: While assigning a Materia to another, copying the type doesn’t make sense.
    return (*this);
}

Ice* Ice::clone() const
{
    Ice* ice = new Ice();
    return (ice);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at *" << target.getName() << std::endl;
    return ;
}