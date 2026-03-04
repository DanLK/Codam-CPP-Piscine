#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main( void ){
  
  Zombie *alfred = newZombie("Alfred");
  alfred->announce();
  alfred->setName("Alfredo");
  alfred->announce();
  delete alfred;

  randomChump("Bert");
  return 0;
}