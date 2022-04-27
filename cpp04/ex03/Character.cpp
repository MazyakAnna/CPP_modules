#include "Character.hpp"
#include "colours.hpp"

/*
The Character possesses an inventory of 4 slots, which means 4 Materias at most.
The inventory is empty at construction.
They equip the Materias in the first empty slot they find.
In case they try to add a Materia to a full inventory,
or use/unequip an unexisting Materia,
don’t do anything (but still, bugs are forbidden).
*/

/*
Save the addresses before calling unequip(), or anything else, but
don’t forget that you have to avoid memory leaks
*/

Character::Character()
{
    this->_name = "NoName";
    for (int i = 0; i < 4; i++)
        this->_slots[i] = NULL;
    std::cout << CONSTR_CLR "Character Constructor called" END_CLR << std::endl;
}

// Your Character must have a constructor taking its name as a parameter.
Character::Character(std::string name)
{
    this->_name = name;
    for (int i = 0; i < 4; i++)
        this->_slots[i] = NULL;
    std::cout << CPY_CONSTR_CLR "Character Copy Constructor called" END_CLR << std::endl;
}

// the Materias must be deleted when a Character is destroyed.
Character::~Character()
{
    std::cout << DESTR_CLR "Character Destructor called" END_CLR << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->_slots[i] != NULL)
            delete(this->_slots[i]);
    }
}

// Any copy (using copy constructor or copy assignment operator)
// of a Character must be deep.
// During copy, the Materias of a Character must be deleted before
// the new ones are added to their inventory.
Character::Character(Character const &src)
{
    this->_name = src.getName();
    for (int i = 0; i < 4; i++)
    {
        if (this->_slots[i] != NULL)
            delete(this->_slots[i]);
        this->_slots[i] = src.getMateria(i)->clone();
    }
}
Character & Character::operator=(Character const &rv)
{
    this->_name = rv.getName();
    for (int i = 0; i < 4; i++)
    {
        if (this->_slots[i] != NULL)
            delete(this->_slots[i]);
        this->_slots[i] = rv.getMateria(i)->clone();
    }
    return(*this);
}

std::string const & Character::getName() const
{
    return(this->_name);
}

const AMateria* Character::getMateria(int idx) const
{
    return (this->_slots[idx]);
}

void Character::equip(AMateria* m)
{
    std::cout << "equiping in process...\n";
    if (m == 0)
    {
        std::cout << "YOU'RE TRYING TO EQUIP AN UNEXISTING MATERIA!\n";
    }
    for (int i = 0; i < 4; i++)
    {
        if (this->_slots[i] == NULL)
        {
            this->_slots[i] = m;
            std::cout << this->_name << ": Materia " << m->getType() << " was equiped in slot " << i << std::endl;
            break ;
        }
    }
}

//The unequip() member function must NOT delete the Materia!
void Character::unequip(int idx)
{
    if (this->_slots[idx] != NULL)
        this->_slots[idx] = NULL;
}

// The use(int, ICharacter&) member function will have to
// use the Materia at the slot[idx],
// and pass the target parameter to the AMateria::use function.
void Character::use(int idx, ICharacter& target)
{
    std::cout << "me: using slot " << idx << ": " ;
    if (this->_slots[idx] != 0)
    {
        this->_slots[idx]->use(target);
    }
}

void Character::showInventory()
{
    std::cout << this->_name << ": current equipment: \n";
            for (int i = 0; i < 4; i++)
            {
                if (this->_slots[i] != NULL)
                    std::cout << "slot " << i << ": " << this->_slots[i]->getType() << std::endl;
            }
}