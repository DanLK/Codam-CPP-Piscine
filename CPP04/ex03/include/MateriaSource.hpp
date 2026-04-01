#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {

  public:

    MateriaSource( void );
    MateriaSource( MateriaSource const & other );
    ~MateriaSource( void );

    MateriaSource& operator=( MateriaSource const & other );

    void learnMateria(AMateria* m) override;
    AMateria* createMateria(std::string const & type) override;

  private:

    AMateria* m_known_materias[4];

};

#endif