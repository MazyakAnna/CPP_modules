#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
protected:
	std::string ideas[100];
public:
	Brain();
	virtual ~Brain();
	Brain(Brain const &);
	Brain 	& 	operator=(Brain const &);

	void		setIdea(std::string idea, int n);
	void		setIdeas(std::string idea);
	std::string	getIdea(unsigned int i) const;
};

#endif