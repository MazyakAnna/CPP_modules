#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP 
# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    virtual ~ShrubberyCreationForm();
    ShrubberyCreationForm(ShrubberyCreationForm const &);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &);

    virtual void action() const;
};

#endif