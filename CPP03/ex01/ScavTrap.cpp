#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap::ClapTrap("Default", 100, 50, 20) {
  
  std::cout << "ScavTrap default constructor called." << std::endl;

}

ScavTrap::ScavTrap( std::string name ) : ClapTrap::ClapTrap(name, 100, 50, 20) {
  
  std::cout << "ScavTrap parametrized constructor called." << std::endl;

}

ScavTrap::ScavTrap( ScavTrap const & other ) : ClapTrap::ClapTrap(other.getName(),
  other.getHitPoints(), other.getEnergyPoints(), other.getAttackDamage()) {
  
  std::cout << "ScavTrap copy constructor called." << std::endl;

}

ScavTrap& ScavTrap::operator=( ScavTrap const & other ){

  std::cout << "ScavTrap copy assignment operator called." << std::endl;
  if (this != &other){
    this->setName(other.getName());
    this->setHitPoints(other.getHitPoints());
    this->setEnergyPoints(other.getEnergyPoints());
    this->setAttackDamage(other.getAttackDamage());
  }
  
  return *this;

}

ScavTrap::~ScavTrap( void ){

  std::cout << "ScavTrap destructor called." << std::endl;

}

void ScavTrap::guardGate( void ){

  std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode." << std::endl;

}