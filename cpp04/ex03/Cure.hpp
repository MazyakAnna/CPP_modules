#ifndef CURE_HPP
# define CURE_HPP
# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	virtual ~Cure();
	Cure(Cure const &);
	Cure & operator=(Cure const &);

	virtual Cure* clone() const;
	virtual void use(ICharacter& target);
};

#endif