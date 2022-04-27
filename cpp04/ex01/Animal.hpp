#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include "Brain.hpp"

class Animal
{
protected:
	std::string _type;
public:
	Animal();
	virtual ~Animal();
	Animal(Animal const &);
	Animal & operator=(Animal const &);

	virtual void	makeSound() const;
	std::string getType() const;
	void setType(std::string type);
};

#endif
