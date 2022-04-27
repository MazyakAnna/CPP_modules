#include "Intern.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "colours.hpp"

Intern::Intern()
{
    std::cout << CONSTR_CLR "Intern Default Constructor called" END_CLR << std::endl;
    return ;
}

Intern::~Intern()
{
    std::cout << DESTR_CLR "Intern Destructor called" END_CLR << std::endl;
    return ;
}

Intern::Intern(Intern const &)
{
    std::cout << CPY_CONSTR_CLR "Intern Copy Constructor called" END_CLR << std::endl;
    return ;
}
Intern & Intern::operator=(Intern const &)
{
    std::cout << ASSIGN_CLR "Intern Assignment operator called" END_CLR << std::endl;
    return (*this);
}

Form * Intern::makeShrubberyCreationForm(std::string target)
{
    Form *newForm = new ShrubberyCreationForm(target);
    return(newForm);
}

Form * Intern::makePresidentialPardonForm(std::string target)
{
    Form *newForm = new PresidentialPardonForm(target);
    return(newForm);
}

Form * Intern::makeRobotomyRequestForm(std::string target)
{
    Form *newForm = new RobotomyRequestForm(target);
    return(newForm);
}

Form * Intern::makeForm(std::string name, std::string target)
{
    std::string names[3] = {"ShrubberyCreationForm", "PresidentialPardonForm", "RobotomyRequestForm"};
    Form*	(Intern::*forms[3])(std::string) = {&Intern::makeShrubberyCreationForm,  &Intern::makePresidentialPardonForm, &Intern::makeRobotomyRequestForm};
    for (int i = 0; i < 3; i++)
    {
        if (name == names[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return ((this->*forms[i])(target));
        }
    }
    std::cout << "Intern failed to create " << name << "! Unknown FormName!" << std::endl;
    return (0);
}