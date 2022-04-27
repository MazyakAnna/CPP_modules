#include "Zombie.hpp"

int main(void)
{
	Zombie *z1;

	std::cout << "TEST1: newZomb in main:" << std::endl;
	z1 = newZombie("Zomb1");
	z1->announce();
	delete(z1);
	std::cout << "TEST2: randomChump in main:" << std::endl;
	randomChump("Zomb2");
	return (0);
}