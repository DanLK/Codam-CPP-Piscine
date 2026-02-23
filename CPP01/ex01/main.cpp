#include "Zombie.hpp"


int main( void ){
  
  Zombie* horde = zombieHorde(3, "pedro");
  
  horde->announce();

  return 0;

}