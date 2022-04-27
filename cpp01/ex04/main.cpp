#include <iostream>
#include <fstream>

int	main(int argc, char **argv)
{
	//Check argnum:
	if (argc != 4)
	{
		std::cout << "Wrong argnum!" << std::endl;
		return (1);
	}
	//Get and check args:
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string filename = argv[1];
	if (s1.empty() || s2.empty() || filename.empty())
	{
		std::cerr << "Wrong nums" << std::endl;
		return (1);
	}
	//Try to open file:
	std::ifstream	ifs(filename);
	if (ifs.fail())
	{
		std::cerr << "Couldn't open input file" << std::endl;
		return (1);
	}
	//Create && open outputfile:
	std::ofstream	ofs(filename.append(".replace"));
	if (ofs.fail())
	{
		ifs.close();
		std::cerr << "Couldn't get access to the .replace file" << std::endl;
		return (1);
	}

	//REPLACING:
	std::string tmp;
	size_t	pos;
	size_t	start;
	while(ifs)
	{
		getline(ifs, tmp);
		pos = 0;
		while (pos < tmp.length())
		{
			start = tmp.find(s1, pos);
			if (start == std::string::npos)
			{
				ofs << tmp.substr(pos, tmp.length() - pos);
				break;
			}
			else
			{
				ofs << tmp.substr(pos, start - pos);
				ofs << s2;
				pos = start + s1.length();
			}
		}
		ofs << std::endl;
	}
	ifs.close();
	ofs.close();
	return (0);
}
