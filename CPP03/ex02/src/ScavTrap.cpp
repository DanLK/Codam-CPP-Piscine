#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap("Default", 100, 50, 20) {
  
  std::cout << "ScavTrap default constructor called." << std::endl;

}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name, 100, 50, 20) {
  
  std::cout << "ScavTrap parametrized constructor called." << std::endl;

}

ScavTrap::ScavTrap( ScavTrap const & other ) : ClapTrap(other._name,
  other._hitPoints, other._energyPoints, other._attackDamage) {
  
  std::cout << "ScavTrap copy constructor called." << std::endl;

}

ScavTrap& ScavTrap::operator=( ScavTrap const & other ){

  std::cout << "ScavTrap copy assignment operator called." << std::endl;
  if (this != &other){
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
  }
  
  return *this;

}

ScavTrap::~ScavTrap( void ){

  std::cout << "ScavTrap destructor called." << std::endl;

}

void ScavTrap::attack( const std::string& target ){

  if (this->_hitPoints > 0 && this->_energyPoints > 0){
    this->_energyPoints--;
    std::cout << "Scav Trap " << this->_name << " attacks " << target <<
    " causing " << this->_attackDamage << " points of damage." << std::endl;
  }
  if (this->_hitPoints <= 0){
    std::cout << "[Insufficient hit points] Scav Trap " << this->_name <<
        " unable to attack " << target << "." << std::endl;
  }
  if (this->_energyPoints <= 0){
    std::cout << "[Insufficient energy points] Scav Trap " << this->_name <<
        " unable to attack " << target << "." << std::endl;
  }

}

void ScavTrap::guardGate( void ){

  std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode." << std::endl;

}

std::ostream& operator<<( std::ostream & o, ScavTrap const & scavtrap){

  o << std::endl << "-----Scav Trap---" << scavtrap.getName() << "-----" << std::endl;
  o << "Hit Points: " << scavtrap.getHitPoints() << std::endl;
  o << "Energy Points: " << scavtrap.getEnergyPoints() << std::endl;
  o << "Attack Damage: " << scavtrap.getAttackDamage() << std::endl;
  o << "-------------------------------------" << std::endl;
  return o;
}