#include "Dog.hpp"
#include "Cat.hpp"
#include "colours.hpp"

int main()
{
	std::cout << std::endl << GREEN_CLR "--- TETS1: LEAKS --- " END_CLR << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;

	std::cout << std::endl << GREEN_CLR " --- MAIN: 5 cats and 5 dogs in animals[10]: --- " END_CLR << std::endl;
	int size = 10;
	Animal *animals[size];
	for (int i = 0; i < size / 2; i++)
		animals[i] = new Cat();
	for (int i = size / 2; i < size; i++)
		animals[i] = new Dog();
	for (int i = 0; i < size; i++)
		animals[i]->makeSound();
	std::cout << " --- deleting animals[10]: --- " << std::endl;
	for (int i = 0; i < size; i++)
		delete(animals[i]);
	
	//DOG DEEP COPY TESTS:
	std::cout << std::endl << GREEN_CLR "--- TETS3: DOG DEEP COPIES --- " END_CLR << std::endl;
	Dog butch;
	{
	Dog tmpButch;
	tmpButch = butch;
	std::cout << "-- tmpButch's idea: " << tmpButch.getBrain()->getIdea(0) << std::endl;
	}
	{
	Dog copydog = butch;
	std::cout << "-- copydog's idea: " << copydog.getBrain()->getIdea(0) << std::endl;
	}
	std::cout << "-- butch's idea: " << butch.getBrain()->getIdea(0) << std::endl;
	
	//CAT DEEP COPY TESTS:
	std::cout << std::endl << GREEN_CLR "--- TETS4: CAT DEEP COPIES --- " END_CLR << std::endl;
	Cat tom;
	std::cout << "-- tom's idea: " << tom.getBrain()->getIdea(0) << std::endl;
	tom.kickCat();
	std::cout << "{" << std::endl;
	{
	Cat tmpTom;
	tmpTom = tom;
	std::cout << "-- tmpTom's idea: " << tmpTom.getBrain()->getIdea(0) << std::endl;
	}
	std::cout << "}" << std::endl;
	std::cout << "{" << std::endl;
	{
	Cat copycat = tom;
	std::cout << "-- copycat's idea: " << copycat.getBrain()->getIdea(0) << std::endl;
	}
	std::cout << "}" << std::endl;
	std::cout << "-- tom's idea: " << tom.getBrain()->getIdea(0) << std::endl;
	return (0);
}