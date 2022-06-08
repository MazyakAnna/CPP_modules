#ifndef ARRAY_HPP
# define ARRAY_HPP
#include <iostream>

template<typename T>
class Array
{
private:
    unsigned int _size;
    T *_arr;
public:
    Array<T>() : _size(0) {this->_arr = new T[0]; }
    Array<T>(unsigned int n) : _size(n)
    {
        this->_arr = new T[n];
        for (unsigned int i = 0; i < n; i++)
            this->_arr[i] = 0;
    }
    Array<T>(Array<T> const &src)
    {
        this->_size = src.size();
        this->_arr = new T[_size];
        for (unsigned int i = 0; i < this->_size; i++)
            this->_arr[i] = src[i];
    }
    virtual ~Array<T>() { delete[] (this->_arr);}
    Array &operator=(Array<T> const &rv)
    {
        delete(this->_arr);
        this->_size = rv.size();
        this->_arr = new T[_size];
        for (unsigned int i = 0; i < this->_size; i++)
            this->_arr[i] = rv[i];
        return (*this);
    }
    unsigned int size() const { return (this->_size);}
    T &operator[](unsigned int n) const
    {
        if (n < 0 || n >= this->_size)
            throw Array::OutOfBoundException();
        return(this->_arr[n]);
    }
    class OutOfBoundException : public std::exception
    {
        virtual const char* what() const throw() {return ("Index is out of bounds!");}
    };
};

template<typename T>
std::ostream &operator<<(std::ostream & o, Array<T> const &rv)
{
    o << "Array(";
    for (unsigned int i = 0; i < rv.size(); i++)
    {
	    o << rv[i];
        o << " ";
    }
    o << ")";
	return o;
}

#endif