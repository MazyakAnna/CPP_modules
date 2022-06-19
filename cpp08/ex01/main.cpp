#include "Span.hpp"
#include <vector>
#include <list>
#include <deque>

int main(int, char**)
{

    std::vector<int> vect(10000, 55);
    vect[5] = 57;
    vect[90] = 90;

    std::vector<int> v4(1, 0);
    for (int i = 1; i <= 9998; i++)
        v4.push_back(i * 3);
    v4.push_back(29997);

    std::list<int> lst(1, 0);
    for (int i = 1; i <= 9998; i++)
        lst.push_back(i * 3);
    lst.push_back(29996);

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    try
    {
        sp.addNumber(199);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

// -----------------------------------
    Span sp2 = Span(10000);
    try
    {
        sp2.addNumber(vect.begin(), vect.end());
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

// -----------------------------------
    Span sp3 = Span(5000);
    try
    {
        sp3.addNumber(vect.begin(), vect.end());
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << sp3.shortestSpan() << std::endl;
        std::cout << sp3.longestSpan() << std::endl;

    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

// -----------------------------------
    Span sp4 = Span(10000);
    try
    {
        sp4.addNumber(v4.begin(), v4.end());
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << sp4.shortestSpan() << std::endl;
        std::cout << sp4.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

// -----------------------------------
    Span sp5 = Span(10000);
    try
    {
        sp5.addNumber(lst.begin(), lst.end());
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << sp5.shortestSpan() << std::endl;
        std::cout << sp5.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }


    // {
    //     Span copy1(sp4);
    //     std::cout << copy1.maxsize() << std::endl;
    //     {
    //     Span copy2(3);
    //     copy2 = copy1;
    //     std::cout << copy2.maxsize() << std::endl;
    //     }
    // }

    return 0;
}