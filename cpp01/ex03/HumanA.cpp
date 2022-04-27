# include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): weapon(weapon), name(name)
{
	return ;
}

HumanA::~HumanA()
{
	return ;
}

void	HumanA::setName(std::string name)
{
	this->name = name;
	return ;
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
	return ;
}