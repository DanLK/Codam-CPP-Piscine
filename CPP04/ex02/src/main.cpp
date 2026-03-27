#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main( void ) {

  std::cout << "[Test 0] Array with cats and dogs-------" << std::endl <<
  std::endl;


  AAnimal* animals[10];
  
  for (int i = 0; i < 10; i++){
    if (i < 5)
    animals[i] = new Dog();
    else
    animals[i] = new Cat(); 
  }
  
  for (int i = 0; i < 10; i++){
    std::cout << i << ": ";
    animals[i]->makeSound();
  }
  
  for (int i = 0; i < 10; i++){
    delete animals[i];
  }

  //Uncomment to see that it's not possible to instantiate the class AAnimal
  // AAnimal animal = AAnimal();


  // std::cout << std::endl << "[Test 1] Deep copies-------" << std::endl << std::endl;
  
  // Brain* dog_brain = new Brain();
  // dog_brain->setIdea("Park!!", 0);
  // dog_brain->setIdea("Ball", 1);
  // dog_brain->setIdea("Foooood", 2);

  // Brain* cat_brain = new Brain();
  // cat_brain->setIdea("Scratch!!", 0);
  // cat_brain->setIdea("Cuddles", 1);
  // cat_brain->setIdea("Mosquito!!", 2);

  // Dog* dog = new Dog();
  // dog->setBrain(dog_brain);
  // Dog dog_copy = Dog(*dog);
  // Cat* cat = new Cat();
  // cat->setBrain(cat_brain);

  // std::cout << "Dog ideas: " << std::endl;
  // std::cout << dog->getBrain()->getIdea(0) << std::endl;
  // std::cout << dog->getBrain()->getIdea(1) << std::endl;
  // std::cout << dog->getBrain()->getIdea(2) << std::endl;


  // std::cout << "Dog copy ideas: " << std::endl;
  // std::cout << dog_copy.getBrain()->getIdea(0) << std::endl;
  // std::cout << dog_copy.getBrain()->getIdea(1) << std::endl;
  // std::cout << dog_copy.getBrain()->getIdea(2) << std::endl;


  // std::cout << "Cat ideas: " << std::endl;
  // std::cout << cat->getBrain()->getIdea(0) << std::endl;
  // std::cout << cat->getBrain()->getIdea(1) << std::endl;
  // std::cout << cat->getBrain()->getIdea(2) << std::endl;

  // delete dog_brain;
  // delete cat_brain;
  // delete dog;
  // delete cat;

  return 0;

}