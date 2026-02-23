#include "Zombie.hpp"
#include <climits>

Zombie* zombieHorde( int N, std::string name ){

  if (N < 1 || N > INT_MAX){
    std::cout << "Invalid horde size. Either too big or too small." << std::endl;
    return NULL;
  }
  Zombie* zombies = new Zombie[N];
  for (int i = 0; i < N; i++){
    zombies[i].setName(name);
  }

  return zombies;

}