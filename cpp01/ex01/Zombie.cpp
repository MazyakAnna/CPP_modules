#include "Zombie.hpp"

Zombie::Zombie (void)
{
	return ;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " destroyed" << std::endl;
	return ;
}

void	Zombie::set_name (std::string name)
{
	this->name = name;
	return ;
}

void	Zombie::announce(void)
{
	std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}