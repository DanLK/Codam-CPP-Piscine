#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void ){

{  
  ScavTrap mario = ScavTrap("Mario");
  FragTrap alexandra = FragTrap("Alexandra");

  std::cout << mario << std::endl;
  std::cout << alexandra << std::endl;

  mario.attack("Alexandra");

  mario.guardGate();
  alexandra.highFivesGuys();
}

  DiamondTrap elisa = DiamondTrap("Elisa");

  std::cout << elisa << std::endl;

  elisa.attack("Mario");
  elisa.whoAmI();
  elisa.beRepaired(10);
  elisa.guardGate();
  elisa.highFivesGuys();
  

  return 0;

}