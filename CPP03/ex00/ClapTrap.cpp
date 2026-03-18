#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name("Default"), _hitPoints(10), _energyPoints(10),
  _attackDamage(0) {
  std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(10),
  _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap parametrized constructor called" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & other ) : _name(other._name),
  _hitPoints(other._hitPoints), _energyPoints(other._energyPoints),
  _attackDamage(other._attackDamage) {

  std::cout << "ClapTrap copy constructor called" << std::endl;

}

ClapTrap::~ClapTrap( void ){
  std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=( ClapTrap const & other ){

  std::cout << "ClapTrap copy assignment operator called" << std::endl;
  if (this != &other){
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
  }
  return *this;

}

std::string ClapTrap::getName( void ) const{

  return this->_name;

}


unsigned int ClapTrap::getHitPoints( void ) const{

  return this->_hitPoints;

}

unsigned int ClapTrap::getEnergyPoints( void ) const{

  return this->_energyPoints;

}

unsigned int ClapTrap::getAttackDamage( void ) const{

  return this->_attackDamage;

}

void ClapTrap::attack( const std::string& target ){

  if (this->_hitPoints > 0 && this->_energyPoints > 0){
    this->_energyPoints--;
    std::cout << "Clap Trap " << this->_name << " attacks " << target <<
    " causing " << this->_attackDamage << " points of damage." << std::endl;
    // std::cout << "Hit points left: " << this->_hitPoints << std::endl;
  }
  if (this->_energyPoints <= 0){
    std::cout << "[Insufficient energy points] Clap Trap " << this->_name <<
        " unable to attack " << target << "." << std::endl;
  }
  if (this->_hitPoints <= 0){
    std::cout << "[Insufficient hit points] Clap Trap " << this->_name <<
        " unable to attack " << target << "." << std::endl;
  }

}

void ClapTrap::takeDamage( unsigned int amount ){

  if (this->_hitPoints <= 0){
    std::cout << "[Hit points are 0] Clap Trap " << this->_name <<
        " unable to take damage. " << std::endl;
        return ;
  }
  else if (amount >= this->_hitPoints){
    std::cout << "Clap trap " << this->_name << " has taken " << this->_hitPoints <<
    " amount of damage." << std::endl;
    this->_hitPoints = 0;
  } 
  else {
    this->_hitPoints -= amount;
    std::cout << "Clap trap " << this->_name << " has taken " << amount <<
    " amount of damage." << std::endl;
  }
  std::cout << "Remaining hit points: " << this->_hitPoints << std::endl;

 }

void ClapTrap::beRepaired( unsigned int amount ){

  if (this->_hitPoints > 0 && this->_energyPoints > 0){
    this->_hitPoints += amount;
    this->_energyPoints--;
    std::cout << "Clap Trap " << this->_name << " has regained " << amount <<
    " hit points." << std::endl;
    std::cout << "Remaining hit points: " << this->_hitPoints << std::endl;
  }
  if (this->_energyPoints <= 0){
    std::cout << "[Insufficient energy points] Clap Trap " << this->_name <<
        " unable to repair itself." << std::endl;
  }
  if (this->_hitPoints <= 0){
    std::cout << "[Insufficient hit points] Clap Trap " << this->_name <<
        " unable to repair itself." << std::endl;
  }
}

std::ostream& operator<<( std::ostream & o, ClapTrap const & claptrap){

  o << std::endl << "-----Clap Trap---" << claptrap.getName() << "-----" << std::endl;
  o << "Hit Points: " << claptrap.getHitPoints() << std::endl;
  o << "Energy Points: " << claptrap.getEnergyPoints() << std::endl;
  o << "Attack Damage: " << claptrap.getAttackDamage() << std::endl;
  o << "-------------------------------------" << std::endl;
  return o;
}
