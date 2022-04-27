#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie lol = Zombie(name);
	lol.announce();
	return ;
}