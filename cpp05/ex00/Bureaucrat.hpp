#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat();
    Bureaucrat(Bureaucrat const &);
    Bureaucrat &operator=(Bureaucrat const &);

    std::string const & getName() const;
    int const & getGrade() const;
    void increment();
    void decrement();

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return ("Grade is too high!");
        }
    };
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return ("Grade is too low!");
        }
    };
};

std::ostream &operator<<(std::ostream & o, Bureaucrat const &rv);

#endif