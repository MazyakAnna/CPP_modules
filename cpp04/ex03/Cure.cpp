#include "Cure.hpp"
#include "ICharacter.hpp"
#include "colours.hpp"

Cure::Cure()
{
    this->_type = "cure";
    std::cout << CONSTR_CLR "CURE Constructor called" END_CLR << std::endl;
    return ;
}


Cure::~Cure()
{
    std::cout << DESTR_CLR "Cure Destructor called" END_CLR << std::endl;
    return ;
}


Cure::Cure(Cure const &src)
{
    std::cout << CPY_CONSTR_CLR "Cure Copy Constructor called" END_CLR << std::endl;
    this->_type = src.getType();
    return ;
}

//Subject: While assigning a Materia to another, copying the type doesn’t make sense.
Cure & Cure::operator=(Cure const &rv)
{
    this->_type = rv.getType(); //Subject: While assigning a Materia to another, copying the type doesn’t make sense.
    return (*this);
}


Cure* Cure::clone() const
{
    Cure* newCure = new Cure();
    return (newCure);
}


void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
    return ;
}