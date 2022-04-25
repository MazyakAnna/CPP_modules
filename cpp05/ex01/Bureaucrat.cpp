#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "colours.hpp"

Bureaucrat::Bureaucrat(): _name("NoName")
{
    std::cout << CONSTR_CLR "Bureaucrat Default Constructor called" END_CLR << std::endl;
    this->_grade = 150;
    return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
    std::cout << CONSTR_CLR "Bureaucrat Constructor called" END_CLR << std::endl;
    try
    {
        if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
        if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
        this->_grade = grade;
    }
    catch (Bureaucrat::GradeTooHighException & e)
    {
        std::cout << RED_CLR "Error upon construction: " << e.what() << " Given grade: 1" END_CLR << std::endl;
        this->_grade = 1;

    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cout << RED_CLR "Error upon construction: " << e.what() << " Given grade: 150" END_CLR << std::endl;
        this->_grade = 150;
    }
    return ;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << DESTR_CLR "Bureaucrat Destructor called" END_CLR << std::endl;
    return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src): _name(src.getName())
{
    std::cout << CPY_CONSTR_CLR "Bureaucrat Copy Constructor called" END_CLR << std::endl;
    this->_grade = src.getGrade();
    return ;    
}
Bureaucrat & Bureaucrat::operator=(Bureaucrat const &rv)
{
    std::cout << ASSIGN_CLR "Bureaucrat Assignment operator called. Note: name will stay the same as it's const!" END_CLR << std::endl;
    this->_grade = rv.getGrade();
    return (*this);
}

std::string const & Bureaucrat::getName() const
{
    return (this->_name);
}
int const & Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void Bureaucrat::increment()
{
    std::cout << "Increment: " << *this << "..." << std::endl;
    try
    {
        if (this->_grade <= 1)
            throw Bureaucrat::GradeTooHighException();
        this->_grade--;
        std::cout << GREEN_CLR "Grade was incremented successfully! New grade: " << this->_grade << END_CLR << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << RED_CLR "Error: " << e.what() << END_CLR << std::endl;
    }
    return ;
}
void Bureaucrat::decrement()
{
    std::cout << "Increment: " << *this << "..." << std::endl;
    try
    {
        if (this->_grade >= 150)
            throw Bureaucrat::GradeTooLowException();
        this->_grade++;
        std::cout << GREEN_CLR "Grade was decremented successfully! New grade: " << this->_grade << END_CLR << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << RED_CLR "Error: " << e.what() << END_CLR << std::endl;
    }
    return ;
}

void Bureaucrat::signForm(Form &target)
{
    try
    {
        target.beSigned(*this);
        std::cout << *this << ", signed " << target << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << *this << ", couldn't sign " << target << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream & o, Bureaucrat const &rv)
{
    o << rv.getName() << ", bureaucrat grade " << rv.getGrade();
    return o;
}