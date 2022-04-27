#include "RobotomyRequestForm.hpp"
#include "colours.hpp"
#include <random>

RobotomyRequestForm::RobotomyRequestForm(): Form("NoName", 72, 45)
{
    std::cout << CONSTR_CLR "RobotomyRequestForm Default Constructor called" END_CLR << std::endl;
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form(target, 72, 45)
{
    std::cout << CONSTR_CLR "RobotomyRequestForm Constructor called" END_CLR << std::endl;
    return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << DESTR_CLR "RobotomyRequestForm Destructor called" END_CLR << std::endl;
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src): Form(src.getName(), 72, 45)
{
    std::cout << CPY_CONSTR_CLR "RobotomyRequestForm Copy Constructor called" END_CLR << std::endl;
    return ;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &)
{
    std::cout << ASSIGN_CLR "RobotomyRequestForm Assignment operator called. Note: name and grades will stay the same as it's const!" END_CLR << std::endl;
    return (*this);
}

void RobotomyRequestForm::action() const
{
        std::cout << "***DRILLING NOISE***" << std::endl;
        srand(time(0));
        if ((rand() % 2) == 1)
        {
            std::cout << this->getName() << " has been robotomized successfully" << std::endl;
        }
        else
            std::cout << "failed to robotomize " << this->getName() << std::endl;
}