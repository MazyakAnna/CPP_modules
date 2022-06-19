#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack<T>() : std::stack<T>() {std::cout << CONSTR_CLR "MutantStack Default Constructor called" END_CLR << std::endl;}
    virtual ~MutantStack<T>() {std::cout << DESTR_CLR "MutantStack Destructor called" END_CLR << std::endl;}
    MutantStack<T>(MutantStack const &src) : std::stack<T>(src){
        std::cout << CPY_CONSTR_CLR "MutantStack Copy Constructor called" END_CLR << std::endl;
        *this = src;};
    MutantStack<T> &operator=(MutantStack const &rv){
        std::cout << ASSIGN_CLR "MutantStack Assignment operator called." END_CLR << std::endl;
        this->c = rv.c;
        return (*this);}

    //Member object "c" in stack - underlying container
    typedef typename std::stack<T>::container_type::iterator iterator;
    typename std::stack<T>::container_type::iterator begin() {return this->c.begin();}
    typename std::stack<T>::container_type::iterator end() {return this->c.end();}

    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    const_iterator cbegin() const {return this->c.cbegin();}
    const_iterator cend() const {return this->c.cend();}
};

# define CPY_CONSTR_CLR "\033[2;33m" //dark yellow
# define ASSIGN_CLR "\033[2;35m" //dark purple
# define DESTR_CLR "\033[2;31m" //dark red
# define CONSTR_CLR "\033[2;32m" //dark green
# define END_CLR "\033[0;0m"

#endif