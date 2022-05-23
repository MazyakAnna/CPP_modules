#include "identify.hpp"
# include <iostream>

// It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
// to use anything you like for the random choice implementation.
Base *generate(void)
{
	Base *base;
	int i = std::rand() % 3;
	switch (i)
	{
		case (0):
			base = new A();
			break;
		case (1):
			base = new B();
			break;
		case (2):
			base = new C();
			break;
	}
	return (base);
}

//It prints the actual type of the object pointed to by p: "A", "B" or "C".
void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "it's class A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "it's class B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "it's class C" << std::endl;
	else
		std::cout << "What is THAT?" << std::endl;
}

// It prints the actual type of the object pointed to by p: "A", "B" or "C".
// Using a pointer inside this function is forbidden.
void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Yeah, it's class A" << std::endl;
	}
	catch (std::exception &e)
	{
		try
		{
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "Yeah, it's class B" << std::endl;
		}
		catch (std::exception &e)
		{
			try
			{
				C &c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "Yeah, it's class C" << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << "No, really, what's this?" << std::endl;
			}
		}
	}
}

int main()
{
	Base* bases[10];
	for (int i = 0; i < 10; i++)
		bases[i] = generate();
	for (int i = 0; i < 10; i++)
	{
		identify(bases[i]);
		identify(*bases[i]);
		std::cout << std::endl;
	}
	for (int i = 0; i < 10; i++)
		delete (bases[i]);

	Base* base = new Base();
	identify(base);
	identify(*base);
	delete (base);
	return (0);
}

