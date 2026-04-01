#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main ( void ){

  // AMateria* ice = new Ice();

  // ICharacter* dani = new Character("Dani");

  // dani->equip(ice);
  // dani->use(0, *dani);
  // dani->use(1, *dani);
  // dani->unequip(0);
  // dani->unequip(1);
  // dani->unequip(2);

  // delete ice;
  // delete dani;

  IMateriaSource* src = new MateriaSource();

  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  
  ICharacter* me = new Character("me");

  
  AMateria* tmp;

  tmp = src->createMateria("ice");
  me->equip(tmp);

  me->printMaterias();

  delete tmp;

  tmp = src->createMateria("cure");
  me->equip(tmp);

  me->printMaterias();
  
  
  me->use(0, *me);
  
  ICharacter* bob = new Character("bob");
  me->use(1, *bob);
  me->unequip(0);

  me->printMaterias();
  
  me->unequip(1);

  me->printMaterias();

  me->unequip(2);
  me->unequip(3);

  delete bob;
  delete tmp;
  delete me;
  delete src;


  return 0;
}