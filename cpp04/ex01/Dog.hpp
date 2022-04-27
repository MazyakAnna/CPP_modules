#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* _brain;
public:
	Dog();
	~Dog();
	Dog(Dog const &);
	Dog & operator=(Dog const &);

	virtual void makeSound() const;
	const Brain* getBrain() const;
};

#endif