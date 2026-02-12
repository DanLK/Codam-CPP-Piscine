#include "Zombie.hpp"

Zombie::Zombie( void ){
  this->_name = "Default zombie";
}

Zombie::Zombie( std::string name ) : _name(name){
}

void Zombie::announce( void ){
  
  std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;

}