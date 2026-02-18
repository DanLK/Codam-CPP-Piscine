#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon) : _name(name), _weapon(weapon){}

HumanA::~HumanA( void ){
  std::cout << "Human A " << this->_name <<
  " has been destroyed" << std::endl;
}

void HumanA::setWeapon( Weapon& weapon ){
  this->_weapon = weapon;
}

void HumanA::attack( void ){
  std::cout << this->_name << " attacks with their " << this->_weapon.getType() <<
  std::endl;
}