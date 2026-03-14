#ifndef SCAVTRAP_H
#define SCAVTRAP_H
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{

  public:

    ScavTrap( void );
    ScavTrap( std::string name );
    ScavTrap( ScavTrap const & other );
    ~ScavTrap( void );

    ScavTrap& operator=(ScavTrap const & other);

    void guardGate( void );

};

std::ostream& operator<<( std::ostream & o, ScavTrap const & scavtrap);

#endif