#include "Zombie.hpp"

int main(void)
{
	Zombie		*zombies;
	int			num;
	std::string	s;

	num = 5;
	s = "KEK";
	std::cout << "TEST1: num = " << num << " ; name = " << s << std::endl;
	zombies = zombieHorde(num, s);
	for (int i = 0; i < num; i++)
		zombies[i].announce();
	delete [] zombies;
	num = 7;
	s = "lol";
	std::cout << "TEST2: num = " << num << " ; name = " << s << std::endl;
	zombies = zombieHorde(num, s);
	for (int i = 0; i < num; i++)
		zombies[i].announce();
	delete [] zombies;
	return (0);
}