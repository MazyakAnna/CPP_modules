#ifndef DOG_HPP
# define DOG_HPP
# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	~Dog();
	Dog(Dog const &);
	Dog & operator=(Dog const &);

	virtual void	makeSound() const;
};

#endif