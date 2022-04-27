#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include <iostream>

#include "AMateria.hpp"

class Character : public ICharacter
{
private:
    AMateria* _slots[4];
    std::string _name;
public:
    Character();
    Character(std::string name);
    virtual ~Character();
    Character(Character const &);
    Character & operator=(Character const &);

    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);
    const AMateria* getMateria(int idx) const;
    void showInventory();
};

#endif