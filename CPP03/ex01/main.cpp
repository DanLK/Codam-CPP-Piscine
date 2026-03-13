#include "ScavTrap.hpp"

int main( void ){

  ScavTrap jannine = ScavTrap("Jannine");
  std::cout << jannine << std::endl;

  jannine.attack("Peter");
  jannine.attack("Peter");
  jannine.attack("Peter");
  jannine.attack("Peter");
  jannine.attack("Peter");

  std::cout << jannine << std::endl;

  jannine.takeDamage(500);
  jannine.takeDamage(3);
  jannine.takeDamage(2);
  
  std::cout << jannine << std::endl;

  jannine.attack("Ben");

  std::cout << jannine << std::endl;

  jannine.beRepaired(5);
  jannine.guardGate();

  return 0;

}