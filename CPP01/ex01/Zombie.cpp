#include "Zombie.hpp"

Zombie::Zombie( void ) : _name("Default zombie:"){
}

Zombie::Zombie( std::string name ) : _name(name){
}

Zombie::~Zombie( void ){

  std::cout << "Zombie " << this->_name << " destroyed." << std::endl;
}

void Zombie::setName(std::string name){
  this->_name = name;
}

void Zombie::announce( void ){
  
  std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;

}

