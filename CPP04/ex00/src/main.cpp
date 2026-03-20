#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main( void ) {

  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();

  std::cout << "--------------Types-----------" << std::endl;
  std::cout << j->getType() << std::endl;
  std::cout << i->getType() << std::endl;
  std::cout << meta->getType() << std::endl;
  
  std::cout << "--------------Sounds-----------" << std::endl;
  j->makeSound();
  i->makeSound(); //will output the cat sound!
  meta->makeSound();

  std::cout << "------------------------------" << std::endl;
  delete j;
  delete i;
  delete meta;

  const WrongAnimal* wrong_meta = new WrongAnimal();
  const WrongAnimal* wrong_cat = new WrongCat();

  std::cout << "--------------Types-----------" << std::endl;
  std::cout << wrong_meta->getType() << std::endl;
  std::cout << wrong_cat->getType() << std::endl;
  
  std::cout << "--------------Sounds-----------" << std::endl;
  wrong_meta->makeSound();
  wrong_cat->makeSound(); //will output the cat sound!
  

  std::cout << "------------------------------" << std::endl;


  delete wrong_meta;
  delete wrong_cat;

  return 0;

}