#ifndef WRONGWANIMAL_HPP
# define WRONGWANIMAL_HPP
# include <iostream>

class WrongAnimal
{
protected:
	std::string _type;
public:
	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal(WrongAnimal const &);
	WrongAnimal & operator=(WrongAnimal const &);

	void	makeSound() const;
	std::string getType() const;
	void setType(std::string type);
};

#endif
