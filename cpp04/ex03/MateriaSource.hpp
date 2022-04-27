#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

class MateriaSource : public IMateriaSource
{
protected:
AMateria* _templates[4];
public:
    MateriaSource();
    MateriaSource(MateriaSource const &src);
    MateriaSource & operator=(MateriaSource const &);
    virtual ~MateriaSource();

    virtual void learnMateria(AMateria*);
    virtual AMateria* createMateria(std::string const & type);
    const AMateria *getTemplate(int idx) const;
    void showMaterias();
};

#endif