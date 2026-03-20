#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap::ClapTrap("Default_clap_name", 100, 50, 30), 
  ScavTrap(), FragTrap() {
  
  this->_name = "Default";
  std::cout << "DiamondTrap default constructor called." << std::endl;

} 

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap::ClapTrap(name + "_clap_name", 100, 50, 30),
  ScavTrap(), FragTrap() {

  this->_name = name;
  std::cout << "DiamondTrap parametrized constructor called" << std::endl;

}

DiamondTrap::DiamondTrap( DiamondTrap const & other ) : 
  ClapTrap::ClapTrap(other.getName() + "_clap_name", other.getHitPoints(),
  other.getEnergyPoints(), other.getAttackDamage()), ScavTrap(), FragTrap() {

    this->_name = other.getName();
    std::cout << "DiamondTrap copy constructor called" << std::endl;

}

DiamondTrap& DiamondTrap::operator=( DiamondTrap const & other ) {

  std::cout << "DiamondTrap copy assignment operator called." << std::endl;
  if (this != &other){
    this->setName(other.getName());
    this->setHitPoints(other.getHitPoints());
    this->setEnergyPoints(other.getEnergyPoints());
    this->setAttackDamage(other.getAttackDamage());
  }
  
  return *this;
}

DiamondTrap::~DiamondTrap( void ) {

    std::cout << "DiamondTrap destructor called." << std::endl;

}

std::string DiamondTrap::getName( void ) const {

  return this->_name;

}

void DiamondTrap::attack( const std::string& target ) {

  this->ScavTrap::attack(target);

}

void DiamondTrap::whoAmI( void ) {

  std::cout << "Diamond Trap name: " << this->_name << std::endl;
  std::cout << "Clap Trap name: " << this->ClapTrap::_name << std::endl;

}

std::ostream& operator<<( std::ostream & o, DiamondTrap const & diamondTrap ){

  o << std::endl << "-----Diamond Trap---" << diamondTrap.getName() << "-----" << std::endl;
  o << "Clap Trap name: " << diamondTrap.ClapTrap::getName() << std::endl;
  o << "Hit Points: " << diamondTrap.getHitPoints() << std::endl;
  o << "Energy Points: " << diamondTrap.getEnergyPoints() << std::endl;
  o << "Attack Damage: " << diamondTrap.getAttackDamage() << std::endl;
  o << "-------------------------------------" << std::endl;
  return o;
}
