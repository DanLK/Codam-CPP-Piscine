#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {

  public:

    Character( void );
    Character( std::string name );
    Character( Character const & other );
    ~Character( void );

    Character& operator=( Character const & other );

    std::string const & getName() const override;
    void equip( AMateria* m ) override;
    void unequip( int idx ) override;
    void use( int idx, ICharacter& target ) override;

    void printMaterias( void ) const override;


  private:

    std::string m_name;
    AMateria* m_inventory[4];
    AMateria* m_trash[100];

};

#endif