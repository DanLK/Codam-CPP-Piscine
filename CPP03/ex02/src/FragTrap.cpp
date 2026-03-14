#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap::ClapTrap("Default", 100, 100, 30) {
  
  std::cout << "FragTrap default constructor called." << std::endl;

}

FragTrap::FragTrap( std::string name ) : ClapTrap::ClapTrap(name, 100, 100, 30) {
  
  std::cout << "FragTrap parametrized constructor called." << std::endl;

}

FragTrap::FragTrap( FragTrap const & other ) : ClapTrap::ClapTrap(other.getName(),
  other.getHitPoints(), other.getEnergyPoints(), other.getAttackDamage()) {
  
  std::cout << "FragTrap copy constructor called." << std::endl;

}

FragTrap& FragTrap::operator=( FragTrap const & other ){

  std::cout << "FragTrap copy assignment operator called." << std::endl;
  if (this != &other){
    this->setName(other.getName());
    this->setHitPoints(other.getHitPoints());
    this->setEnergyPoints(other.getEnergyPoints());
    this->setAttackDamage(other.getAttackDamage());
  }
  
  return *this;

}

FragTrap::~FragTrap( void ){

  std::cout << "FragTrap destructor called." << std::endl;

}

void FragTrap::highFivesGuys( void ){

  std::cout << "Give " << this->getName() << " those 5!!" << std::endl;

}

std::ostream& operator<<( std::ostream & o, FragTrap const & fragtrap){

  o << std::endl << "-----Frag Trap---" << fragtrap.getName() << "-----" << std::endl;
  o << "Hit Points: " << fragtrap.getHitPoints() << std::endl;
  o << "Energy Points: " << fragtrap.getEnergyPoints() << std::endl;
  o << "Attack Damage: " << fragtrap.getAttackDamage() << std::endl;
  o << "-------------------------------------" << std::endl;
  return o;
}