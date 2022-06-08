#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	Array<float> *emptyArr = new Array<float>();
	Array<float> *kek = new Array<float>(5);
	for (unsigned int i = 0; i < kek->size(); i++)
		std::cout << (*kek)[i] << " ";
	std::cout << std::endl;
	for (unsigned int i = 0; i < kek->size(); i++)
		(*kek)[i] = 0.5 + i;
	for (unsigned int i = 0; i < kek->size(); i++)
		std::cout << (*kek)[i] << " ";
	std::cout << std::endl;
	(*emptyArr) = (*kek);
	for (unsigned int i = 0; i < emptyArr->size(); i++)
		std::cout << (*emptyArr)[i] << " ";
	delete(emptyArr);
	delete(kek);
	std::cout << std::endl << " --- " << std::endl;

	Array<int> lol(5);
	for (int i = 0; i < 5; i++)
		std::cout << lol[i] << " ";
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
		lol[i] = 100 + i;
	for (int i = 0; i < 5; i++)
		std::cout << lol[i] << " ";
	std::cout << std::endl;
	Array<int> empty2(0);

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;

	std::cout << "Double Array: " << std::endl;
	int l = 5;
	int m = 10;
	Array< Array<int> > megaarray(l);
	Array<int> tmp(m);
	for (int i = 0; i < l; i++)
	{
		megaarray[i] = tmp;
		for (int j = 0; j < m; j++)
		 	(megaarray[i])[j] = i*10 + j;
	}
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < m; j++)
			std::cout << megaarray[i][j] << " ";
		std::cout << std::endl;
	}
    return 0;
}