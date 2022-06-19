#include "MutantStack.hpp"
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

int main()
{
    MutantStack<int> mstack;
    mstack.push(1);
    mstack.push(3);
    std::cout << "top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(7);
    mstack.push(9);

    // --------------------------------- iterators as pointers check:
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << " + 1 = ";
        *it += 1;
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << std::endl;
    //-------------------------------- copy constructor check
    std::stack<int> s(mstack);
    MutantStack<int> ms0(mstack);
    std::cout << std::endl;
    while (!s.empty())
    {
        std::cout << ms0.top() << " = ";
        s.pop();
        std::cout << ms0.top() << std::endl;
        ms0.pop();
    }

    std::cout << std::endl;
    //-------------------------------- Const iter check
    MutantStack<int>::const_iterator c_it = mstack.cbegin();
    MutantStack<int>::const_iterator c_ite = mstack.cend();
    ++c_it;
    --c_it;
    while (c_it != c_ite)
    {
        std::cout << *c_it << std::endl;
        //*c_it += 1; shoudn't compile as it's const
        ++c_it;
    }
    
    std::cout << std::endl;
    //-------------------------------- Assignment check
    MutantStack<int> ms1;
    ms1 = mstack;
    MutantStack<int>::const_iterator ms1_it = ms1.cbegin();
    MutantStack<int>::const_iterator ms1_ite = ms1.cend();
    for (ms1_it = ms1.cbegin(); ms1_it != ms1_ite; ++ms1_it)
        std::cout << *ms1_it << std::endl;
    
    std::cout << std::endl;
    //-------------------------------- algorithm check: FIND "4" and add 2 steps
    MutantStack<int>::iterator result = std::find(begin(ms1), end(ms1), 4);
    result += 2;
    std::cout << "4 + 4 = " << *result << std::endl;

    return (0);
}