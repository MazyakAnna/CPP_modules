#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP 
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    virtual ~RobotomyRequestForm();
    RobotomyRequestForm(RobotomyRequestForm const &);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &);

    virtual void action() const;
};

#endif