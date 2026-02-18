#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : _type(type){}

Weapon::~Weapon( void ){
  std::cout << "Weapon " << this->_type << " has been destroyed." << std::endl;
}

const std::string& Weapon::getType( void ){
  return this->_type;
}

void Weapon::setType( std::string type ){
  this->_type = type;
}