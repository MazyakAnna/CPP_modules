#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* nz = new Zombie[N];
	for (int i = 0; i < N; i++)
		nz[i].set_name(name);
	return (nz);
}