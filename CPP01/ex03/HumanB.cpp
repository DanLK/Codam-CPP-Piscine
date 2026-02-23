#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name), _weapon(NULL){}

HumanB::~HumanB( void ){
  std::cout << "HumanB " << this->_name << " has been destroyed." << std::endl;
}

Weapon* HumanB::getWeapon( void ){
  return this->_weapon;
}

void HumanB::setWeapon( Weapon& weapon ){
  this->_weapon = &weapon;
}

void HumanB::attack( void ){
  std::cout << this->_name << " attacks with their " <<
  this->_weapon->getType() << std::endl;
}

