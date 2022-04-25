#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "colours.hpp"

Form::Form(): _name("NoName"), _signed(0), _grade_s(150), _grade_ex(150)
{
    std::cout << CONSTR_CLR "Form Default Constructor called" END_CLR << std::endl;
    return ;
}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute):
    _name(name), _signed(0), _grade_s(grade_to_sign), _grade_ex(grade_to_execute)
{
    std::cout << CONSTR_CLR "Form Constructor called" END_CLR << std::endl;
    try
    {
        if (grade_to_sign > 150 || grade_to_execute > 150)
            throw Form::GradeTooLowException();
        if (grade_to_sign < 1 || grade_to_execute < 1)
            throw Form::GradeTooHighException();
    }
    catch (std::exception &e)
    {
        std::cout << RED_CLR "Error upon construction: Form: " << e.what() << END_CLR << std::endl;
    }
    return ;
}

Form::~Form()
{
    std::cout << DESTR_CLR "Form Destructor called" END_CLR << std::endl;
    return ;
}
Form::Form(Form const &src):
    _name(src.getName()), _grade_s(src.getGradeSign()), _grade_ex(src.getGradeExec())
{
    std::cout << CPY_CONSTR_CLR "Form Copy Constructor called" END_CLR << std::endl;
    this->_signed = src.getStatus();
    return ;
}
Form & Form::operator=(Form const &rv)
{
    std::cout << ASSIGN_CLR "Form Assignment operator called. Note: name and grades will stay the same as it's const!" END_CLR << std::endl;
    this->_signed = rv.getStatus();
    return (*this);
}

std::string const & Form::getName() const
{
    return (this->_name);
}
int const & Form::getGradeSign() const
{
    return (this->_grade_s);
}
int const & Form::getGradeExec() const
{
    return (this->_grade_ex);
}
bool const & Form::getStatus() const
{
    return (this->_signed);
}

void Form::beSigned(Bureaucrat &signer)
{
    if (signer.getGrade() > this->_grade_s)
    {
        throw Form::GradeTooLowException();
    }
    else
    {
        this->_signed = 1;
    }
}

std::ostream &operator<<(std::ostream & o, Form const &rv)
{
    o << rv.getName() << " Form (grade to sign = " << rv.getGradeSign() << ", grade to execute = " << rv.getGradeExec() << ", signed = " << rv.getStatus() << ")";
    return o;
}