#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <set>

class Span
{
private:
    std::multiset<int> _set;
    unsigned int _N;
    Span();

public:
    Span(unsigned int N);
    ~Span();
    Span(Span const &);
    Span &operator=(Span const &);

    unsigned int const & maxsize() const;
    std::multiset<int> const & getContent() const;

    void addNumber(int n);
    int shortestSpan();
    int longestSpan();

    template <typename iterT>
    void addNumber(iterT begin, iterT end)
    {
        size_t space = this->_N - this->_set.size();
        size_t dist = std::distance(begin, end);
        if (space < dist)
            throw MaximumElementsException();
        this->_set.insert(begin, end);   
    }

    class MaximumElementsException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return ("Exception: attempt to add to Span more elements than its maximum");
        }
    };

    class SpanException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return ("Exception: Not enough elements to find a span");
        }
    };
};


# define CPY_CONSTR_CLR "\033[2;33m" //dark yellow
# define ASSIGN_CLR "\033[2;35m" //dark purple
# define DESTR_CLR "\033[2;31m" //dark red
# define CONSTR_CLR "\033[2;32m" //dark green
# define END_CLR "\033[0;0m"

#endif