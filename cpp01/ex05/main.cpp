#include "Karen.hpp"

int main()
{
	Karen kar;

	std::cout << "KARREN WILL DEBUG NOW!" << std::endl;
	kar.complain("DEBUG");
	std::cout << "KARREN WILL ERROR NOW!" << std::endl;
	kar.complain("ERROR");
	std::cout << "KARREN WILL INFO NOW!" << std::endl;
	kar.complain("INFO");
	std::cout << "KARREN WILL WARNING NOW!" << std::endl;
	kar.complain("WARNING");
	std::cout << "KARREN WILL DO NOTHING NOW!" << std::endl;
	kar.complain("aUIJWOD");
	return (0);
}