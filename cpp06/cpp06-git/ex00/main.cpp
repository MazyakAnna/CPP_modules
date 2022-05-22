#include "Converter.hpp"

int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		std::cout << argv[1] << std::endl;
		try
		{
			Converter converter(argv[1]);
			converter.convert();
		}
		catch (std::exception &e)
    	{
			std::cout << "Error: " << e.what() << std::endl;
    	}
	}
	else
		std::cout << "Usage: program requires 1 argument" << std::endl;
	return (0);
}

