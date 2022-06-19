#include "Span.hpp"

Span::Span()
{
    std::cout << CONSTR_CLR "Span Default Constructor called" END_CLR << std::endl;
    this->_N = 0;
    this->_set = std::multiset<int>();
    return ;
}

Span::Span(unsigned int N): _N(N)
{
    std::cout << CONSTR_CLR "Span Constructor called" END_CLR << std::endl;
    this->_set = std::multiset<int>();
    return ;
}

Span::~Span()
{
    std::cout << DESTR_CLR "Span Destructor called" END_CLR << std::endl;
    return ;
}

Span::Span(Span const &src): _N(src.maxsize())
{
    std::cout << CPY_CONSTR_CLR "Span Copy Constructor called" END_CLR << std::endl;
    this->_set = src.getContent();
    return ;
}

Span & Span::operator=(Span const &rv)
{
    std::cout << ASSIGN_CLR "Span Assignment operator called." END_CLR << std::endl;
    this->_N = rv.maxsize();
    this->_set = rv.getContent();
    return (*this);
}

unsigned int const & Span::maxsize() const
{
    return(this->_N);
}

std::multiset<int> const & Span::getContent() const
{
    return(this->_set);
}

void Span::addNumber(int n)
{
    if (this->_set.size() < this->_N)
        this->_set.insert(n);
    else
        throw MaximumElementsException();
}

int Span::shortestSpan()
{
    if (this->_set.size() < 2)
        throw SpanException();
    std::multiset<int>::iterator it = this->_set.begin();
    std::multiset<int>::iterator it2 = this->_set.begin();
    int span = std::abs(*it - *(++it2));

    for (it = this->_set.begin(); it2 != this->_set.end(); ++it)
    {
        if (std::abs(*it - *(it2)) < span)
            span = std::abs(*it - *(it2));
        ++it2;
    }
    return (span);
}

int Span::longestSpan()
{
    if (this->_set.size() < 2)
        throw SpanException();
    std::multiset<int>::iterator max = std::max_element(this->_set.begin(), this->_set.end());
    std::multiset<int>::iterator min = std::min_element(this->_set.begin(), this->_set.end());

    return (*max - *min);
}
