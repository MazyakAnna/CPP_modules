#include "Karen.hpp"

Karen::Karen(void)
{
	return ;
}

Karen::~Karen(void)
{
	return ;
}

void Karen::debug( void )
{
	std::cerr << "I love to get extra bacon for my ";
	std::cerr << "7XL-double-cheese-triple-pickle-special-ketchup burger.";
	std::cerr << " I just love it!" << std::endl;
	return ;
}

void Karen::info( void )
{
	std::cerr << "I cannot believe adding extra bacon cost more money. ";
	std::cerr << "You don’t put enough! ";
	std::cerr << "If you did I would not have to ask for it!" << std::endl;
	return ;
}

void Karen::warning( void )
{
	std::cerr << "I think I deserve to have some extra bacon for free. ";
	std::cerr << "I’ve been coming here for years ";
	std::cerr << "and you just started working here last month." << std::endl;
	return ;
}

void Karen::error( void )
{
	std::cerr << "This is unacceptable, I want to speak to the manager now." << std::endl;
	return ;
}

void Karen::mute( void )
{
	return ;
}

void Karen::complain( std::string level )
{
	void	(Karen::*func[5])(void) = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error, &Karen::mute};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = 0;
	while (level.compare(levels[i]) != 0 && i < 4)
		i++;
	(this->*func[i])();
}