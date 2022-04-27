#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>

class Form;

class Intern
{
private:
    Form * makeShrubberyCreationForm(std::string target);
    Form * makePresidentialPardonForm(std::string target);
    Form * makeRobotomyRequestForm(std::string target);
public:
    Intern();
    Intern(std::string name, int grade);
    ~Intern();
    Intern(Intern const &);
    Intern &operator=(Intern const &);

    Form* makeForm(std::string name, std::string target);
};

std::ostream &operator<<(std::ostream & o, Intern const &rv);

#endif