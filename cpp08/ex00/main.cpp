#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main(int, char**)
{
	std::vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    std::list<double> l;
    l.push_back(3.9);
    l.push_back(4);
    l.push_back(3.2);
    l.push_back(4.9);
    l.push_back(5.9);

    std::deque<float> d;
    d.push_back(2.5);
    d.push_back(3.5);
    d.push_back(4.5);
    d.push_back(5.0);

    try
    {
        std::vector<int>::iterator t = easyfind(v, 3);
        std::cout << *t << std::endl;
        std::cout << *easyfind(l, 4) << std::endl;
        std::cout << *easyfind(d, 5) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "couldn't find..." << std::endl;
    }
    try
    {
        std::cout << *easyfind(v, 2) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "couldn't find..." << std::endl;
    }
    try
    {
        std::cout << *easyfind(l, 2) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "couldn't find..." << std::endl;
    }try
    {
        std::cout << *easyfind(d, 2) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "couldn't find..." << std::endl;
    }
    return 0;
}