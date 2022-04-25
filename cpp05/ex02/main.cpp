#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "colours.hpp"

int main()
{
    Bureaucrat *rookie = new Bureaucrat("Rookie", 150);
    Bureaucrat *boss = new Bureaucrat("Boss", 1);
    ShrubberyCreationForm *lol = new ShrubberyCreationForm("Shrub_square");
    RobotomyRequestForm *robo = new RobotomyRequestForm("rob");
    PresidentialPardonForm *pardForm = new PresidentialPardonForm("LOL");

    std::cout << "SIGNING FORMS:" << std::endl;
    rookie->signForm(*lol);
    boss->signForm(*lol);
    rookie->signForm(*pardForm);
    boss->signForm(*pardForm);
    rookie->signForm(*robo);
    boss->signForm(*robo);

    std::cout << "EXECUTING FORMS:" << std::endl;
    rookie->executeForm(*lol);
    boss->executeForm(*lol);
    rookie->executeForm(*pardForm);
    boss->executeForm(*pardForm);
    rookie->executeForm(*robo);
    boss->executeForm(*robo);

    delete (rookie);
    delete boss;
    delete lol;
    delete robo;
    delete pardForm;
    return 0;
}