#ifndef CAT_HPP
# define CAT_HPP
# include <iostream>
# include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	~Cat();
	Cat(Cat const &);
	Cat & operator=(Cat const &);

	virtual void	makeSound() const;
};

#endif