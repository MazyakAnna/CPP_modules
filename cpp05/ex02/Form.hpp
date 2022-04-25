#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>

class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool _signed;
    const int _grade_s;
    const int _grade_ex;
public:
    Form();
    Form(std::string name, int grade_to_sign, int grade_to_execute);
    virtual ~Form();
    Form(Form const &);
    Form &operator=(Form const &);

    std::string const & getName() const;
    int const & getGradeSign() const;
    int const & getGradeExec() const;
    bool const & getStatus() const;
    void beSigned(Bureaucrat const &);
    void execute(Bureaucrat const &) const;
    virtual void action() const = 0;

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

std::ostream &operator<<(std::ostream & o, Form const &rv);

#endif