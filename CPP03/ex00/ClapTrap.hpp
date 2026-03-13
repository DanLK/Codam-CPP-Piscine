#ifndef CLAPTRAP_H
#define CLAPTRAP_H
#include <iostream>

class ClapTrap {

  public:

    ClapTrap( void );
    ClapTrap( std::string name );
    ClapTrap( ClapTrap const & other );
    ~ClapTrap( void );
    
    ClapTrap& operator=( ClapTrap const & other );

    std::string getName( void ) const;
    unsigned int getHitPoints( void ) const;
    unsigned int getEnergyPoints( void ) const;
    unsigned int getAttackDamage( void ) const;

    void attack( const std::string& target );
    void takeDamage( unsigned int amount );
    void beRepaired( unsigned int amount );

  private:

    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;

};

std::ostream& operator<<( std::ostream & o, ClapTrap const & claptrap);

#endif