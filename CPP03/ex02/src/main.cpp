#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ){

  ScavTrap mario = ScavTrap("Mario");
  FragTrap alexandra = FragTrap("Alexandra");

  std::cout << mario << std::endl;
  std::cout << alexandra << std::endl;

  mario.attack("Alexandra");
  mario.guardGate();
  
  alexandra.attack("Mario");
  alexandra.highFivesGuys();

  return 0;

}