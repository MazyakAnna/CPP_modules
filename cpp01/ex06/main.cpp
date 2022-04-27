#include "Karen.hpp"

int main(int argc, char **argv)
{
	Karen kar;

	if (argc == 2)
		kar.complain(argv[1]);
	else
		std::cerr << "Wrong argnum" << std::endl;
	return (0);
}