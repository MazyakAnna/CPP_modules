#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void iter(T *addr, unsigned int len, void (*func)(T &))
{
    for (unsigned int i = 0; i < len; i++)
    {
        func(addr[i]);
    }
}

// template<typename T>
// void iter(T *addr, unsigned int len, void (func)(T const &))
// {
//     for (unsigned int i = 0; i < len; i++)
//     {
//         func(addr[i]);
//     }
// }


#endif