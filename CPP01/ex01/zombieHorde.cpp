#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){

  //Check that the int is positive
  Zombie* zombies = new Zombie[N];
  for (int i = 0; i < N; i++){
    zombies[i].setName(name);
  }

  return zombies;

}