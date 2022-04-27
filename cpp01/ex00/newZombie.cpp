#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *nZ = new Zombie(name);
	return (nZ);
}