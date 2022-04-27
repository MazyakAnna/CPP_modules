#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->setName(name);
	return ;
}

HumanB::~HumanB()
{
}

void	HumanB::setName(std::string name)
{
	this->name = name;
	return ;
}

void	HumanB::attack(void)
{
	std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon weapon)
{
	this->weapon = &weapon;
	return ;
}