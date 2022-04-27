#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "colours.hpp"


/*
MateriaSource must be able to learn "templates" of Materias to
create them when needed. Then, you will be able to generate a new Materia using just
a string that identifies its type.
*/

//Constructor
MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        this->_templates[i] = NULL;
    std::cout << CONSTR_CLR "MateriaSource Constructor called" END_CLR << std::endl;
}

//destructor
MateriaSource::~MateriaSource()
{
    std::cout << DESTR_CLR "MateriaSource Destructor called" END_CLR << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->_templates[i] != NULL)
            delete(this->_templates[i]);
    }
}

//copy constructor
MateriaSource::MateriaSource(MateriaSource const &src)
{
    for (int i = 0; i < 4; i++)
    {
        if (src.getTemplate(i) != 0)
            this->_templates[i] = src.getTemplate(i)->clone();
        else
            this->_templates[i] = 0;
        std::cout << CPY_CONSTR_CLR "MateriaSource Copy Constructor called" END_CLR << std::endl;
    }
}

MateriaSource & MateriaSource::operator=(MateriaSource const &rv)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_templates[i] != NULL)
            delete(this->_templates[i]);
        if (rv.getTemplate(i) != 0)
            this->_templates[i] = rv.getTemplate(i)->clone();
        else
            this->_templates[i] = 0;
    }
    std::cout << ASSIGN_CLR "MateriaSource Assignment operator called" END_CLR << std::endl;
    return(*this);
}

// Copies the Materia passed as a parameter and store it in memory
// so it can be cloned later.
// Like the Character, the MateriaSource can know at most 4 Materias.
// They are not necessarily unique.
void MateriaSource::learnMateria(AMateria* m)
{
    if (m == 0)
    {
        std::cout << "YOU'RE TRYING TO LEARN AN UNEXISTING MATERIA!" << std::endl;
        return ;
    }
    for (int i = 0; i < 4; i++)
    {
        if (this->_templates[i] == NULL)
        {
            std::cout << "MateriaSource learned materia " << m->getType() << " in slot " << i << std::endl;
            this->_templates[i] = m;
            break ;
        }
    }
}

// Returns a new Materia.
// The latter is a copy of the Materia previously learned by the MateriaSource whose type equals the one passed as parameter.
// Returns 0 if the type is unknown.
AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {   
        if (this->_templates[i] != 0 && this->_templates[i]->getType() == type)
        {
            std::cout << "Materia " << type << " was created by MateriaSource" << std::endl;
            return ((this->_templates[i]->clone()));
        }
    }
    std::cout << RED_CLR "Creation of materia " << type << " has FAILED" END_CLR << std::endl;
    return (0);
}

const AMateria * MateriaSource::getTemplate(int idx) const
{
    return (this->_templates[idx]);
}

void MateriaSource::showMaterias()
{
    std::cout << "LEARNED MATERIAS:" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->_templates[i] != NULL)
            std::cout << "slot " << i << ": " << this->_templates[i]->getType() << std::endl;
    }
}