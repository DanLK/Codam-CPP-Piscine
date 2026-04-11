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

  {
    std::cout << "[Test 01] Subject Main" << std::endl;

    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    // for (int i = 0; i < 5; i++)
    //   src->learnMateria(new Ice());

    ICharacter* me = new Character("me");

    
    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);

    me->printMaterias();

    tmp = src->createMateria("cure");
    me->equip(tmp);

    me->printMaterias();
    
    
    
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    me->unequip(0);

    me->printMaterias();
    
    me->unequip(1);

    me->printMaterias();

    me->unequip(2);
    me->unequip(3);

    delete bob;
    delete me;
    delete src;
  }

  // {
  //   std::cout << "[Test 02] Unequipping materias" << std::endl;

  //   ICharacter* fido = new Character("Fido");

  //   for (int i = 0; i < 100; i++){
  //     fido->equip(new Ice());
  //     fido->unequip(0);
  //   }
  //   fido->equip(new Cure());
  //   fido->equip(new Cure());
  //   fido->equip(new Cure());
  //   fido->equip(new Cure());
    
  //   AMateria* cure = new Cure(); // If you try to equip when it's full, ownership is not taken
  //   fido->equip(cure);
  //   delete cure;

  //   fido->printMaterias();
  //   fido->unequip(0);
  //   fido->printMaterias();

  //   delete fido;
  // }

  return 0;
}