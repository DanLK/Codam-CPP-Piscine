#include "Dog.hpp"

Dog::Dog( void ) : AAnimal("Dog") {

  this->m_brain = new Brain();
  std::cout << "Dog default constructor called." << std::endl;

}

Dog::Dog( std::string type ) : AAnimal("Dog") {

  this->m_brain = new Brain();
  std::cout << "Dog parametrized constructor called with parameter " <<
  type << std::endl;

}

Dog::Dog( Dog const & other ) : AAnimal(other.m_type) {

  this->m_brain= new Brain();
  for (int i = 0; i < 100; i++){
    this->m_brain->setIdea(other.m_brain->getIdea(i), i);
  }
  std::cout << "Dog copy constructor called." << std::endl;

}

Dog::~Dog( void ) {

  delete this->m_brain;
  std::cout << "Dog destructor called." << std::endl;

}

Dog& Dog::operator=( Dog const & other ){

  if (this != &other){
    this->m_type = other.m_type;
    this->m_brain= new Brain();
    for (int i = 0; i < 100; i++){
      this->m_brain->setIdea(other.m_brain->getIdea(i), i);
    }
  }

  return *this;

}

Brain* Dog::getBrain( void ) const {

  return this->m_brain;
}

void Dog::setBrain( Brain* brain ) {

  for (int i = 0; i < 100; i++){
      this->m_brain->setIdea(brain->getIdea(i), i);
  }

}

void Dog::makeSound( void ) const {

  std::cout << "Guau guau!" << std::endl;

}