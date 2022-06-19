#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <algorithm>

template<typename T>
typename T::iterator easyfind(T &cont, int x)
{
    typename T::iterator res = std::find(cont.begin(), cont.end(), x);
    if (res == cont.end())
        throw std::exception();
    else return (res);
}

#endif