#ifndef ICE_HPP
# define ICE_HPP
# include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
	virtual ~Ice();
	Ice(Ice const &);
	Ice & operator=(Ice const &);

	virtual Ice* clone() const;
	virtual void use(ICharacter& target);
};

#endif
