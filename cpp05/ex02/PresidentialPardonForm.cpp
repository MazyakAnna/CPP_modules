#include "PresidentialPardonForm.hpp"
#include "colours.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("NoName", 25, 5)
{
    std::cout << CONSTR_CLR "PresidentialPardonForm Default Constructor called" END_CLR << std::endl;
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form(target, 25, 5)
{
    std::cout << CONSTR_CLR "PresidentialPardonForm Constructor called" END_CLR << std::endl;
    return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << DESTR_CLR "PresidentialPardonForm Destructor called" END_CLR << std::endl;
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src): Form(src.getName(), 25, 5)
{
    std::cout << CPY_CONSTR_CLR "PresidentialPardonForm Copy Constructor called" END_CLR << std::endl;
    return ;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const &)
{
    std::cout << ASSIGN_CLR "PresidentialPardonForm Assignment operator called. Note: name and grades will stay the same as it's const!" END_CLR << std::endl;
    return (*this);
}

void PresidentialPardonForm::action() const
{
    std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}