#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main( void ) {

  {
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "--------------Types-----------" << std::endl;
    std::cout << animal->getType() << std::endl;
    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;
    
    std::cout << "--------------Sounds-----------" << std::endl;
    animal->makeSound();
    dog->makeSound();
    cat->makeSound(); //will output the cat sound!

    std::cout << "------------------------------" << std::endl;
    delete animal;
    delete dog;
    delete cat;
  }


 {
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
  }

  return 0;

}