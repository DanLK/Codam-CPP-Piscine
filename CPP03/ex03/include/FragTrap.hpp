#ifndef FRAGTRAP_H
#define FRAGTRAP_H
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{

  public:

    FragTrap( void );
    FragTrap( std::string name );
    FragTrap( FragTrap const & other );
    ~FragTrap( void );

    FragTrap& operator=(FragTrap const & other);

    void highFivesGuys( void );

};

std::ostream& operator<<( std::ostream & o, FragTrap const & fragtrap);

#endif