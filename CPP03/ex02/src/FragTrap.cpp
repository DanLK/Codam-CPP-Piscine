#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap("Default", 100, 100, 30) {
  
  std::cout << "FragTrap default constructor called." << std::endl;

}

FragTrap::FragTrap( std::string name ) : ClapTrap(name, 100, 100, 30) {
  
  std::cout << "FragTrap parametrized constructor called." << std::endl;

}

FragTrap::FragTrap( FragTrap const & other ) : ClapTrap(other.getName(),
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

void FragTrap::attack( const std::string& target ){

  if (this->_hitPoints > 0 && this->_energyPoints > 0){
    this->_energyPoints--;
    std::cout << "Frag Trap " << this->_name << " attacks " << target <<
    " causing " << this->_attackDamage << " points of damage." << std::endl;
  }
  if (this->_hitPoints <= 0){
    std::cout << "[Insufficient hit points] Frag Trap " << this->_name <<
        " unable to attack " << target << "." << std::endl;
  }
  if (this->_energyPoints <= 0){
    std::cout << "[Insufficient energy points] Frag Trap " << this->_name <<
        " unable to attack " << target << "." << std::endl;
  }

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