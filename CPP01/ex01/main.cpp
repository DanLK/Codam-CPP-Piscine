#include "Zombie.hpp"


int main( void ){
  
  int horde_size = 4;

  Zombie* horde = zombieHorde(horde_size, "Pedro");
  
  if (!horde)
    return 1;
  for (int i = 0; i < horde_size; i++){
    horde[i].announce();
  }

  delete[] horde;

  return 0;

}