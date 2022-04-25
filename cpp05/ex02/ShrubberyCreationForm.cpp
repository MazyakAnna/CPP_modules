#include "ShrubberyCreationForm.hpp"
#include "colours.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): Form("NoName", 145, 137)
{
    std::cout << CONSTR_CLR "ShrubberyCreationForm Default Constructor called" END_CLR << std::endl;
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form(target, 145, 137)
{
    std::cout << CONSTR_CLR "ShrubberyCreationForm Constructor called" END_CLR << std::endl;
    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << DESTR_CLR "ShrubberyCreationForm Destructor called" END_CLR << std::endl;
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src): Form(src.getName(), 145, 137)
{
    std::cout << CPY_CONSTR_CLR "ShrubberyCreationForm Copy Constructor called" END_CLR << std::endl;
    return ;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &)
{
    std::cout << ASSIGN_CLR "ShrubberyCreationForm Assignment operator called. Note: name and grades will stay the same as it's const!" END_CLR << std::endl;
    return (*this);
}

void ShrubberyCreationForm::action() const
{
        std::ofstream outfile;
        outfile.open(this->getName());
        outfile << "                ,@@@@@@@," << std::endl; 
        outfile << "        ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl; 
        outfile << "     ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl; 
        outfile << "    ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl; 
        outfile << "    %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl; 
        outfile << "    %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl; 
        outfile << "    `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl; 
        outfile << "        |o|        | |         | |" << std::endl; 
        outfile << "        |.|        | |         | |" << std::endl; 
        outfile << " \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_ " << std::endl;
        outfile.close();
}