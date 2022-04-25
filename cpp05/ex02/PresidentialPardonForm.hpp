#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP 
# include "Form.hpp"

class PresidentialPardonForm : public Form
{
public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    virtual ~PresidentialPardonForm();
    PresidentialPardonForm(PresidentialPardonForm const &);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &);

    virtual void action() const;
};

#endif