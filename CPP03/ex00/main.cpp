#include "ClapTrap.hpp"

int main( void ){

  ClapTrap jannine = ClapTrap("Jannine");
  std::cout << jannine << std::endl;

  jannine.attack("Peter");
  jannine.attack("Peter");
  jannine.attack("Peter");
  jannine.attack("Peter");
  jannine.attack("Peter");

  std::cout << jannine << std::endl;

  jannine.takeDamage(5);
  jannine.takeDamage(3);
  jannine.takeDamage(2);
  
  std::cout << jannine << std::endl;

  jannine.attack("Ben");

  std::cout << jannine << std::endl;

  jannine.beRepaired(5);
  jannine.takeDamage(1);

  return 0;
}