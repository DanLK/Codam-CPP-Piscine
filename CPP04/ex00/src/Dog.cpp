#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog") {
  
  std::cout << "Dog default constructor called." << std::endl;

}

Dog::Dog( std::string type ) : Animal("Dog") {

  std::cout << "Dog parametrized constructor called with parameter " <<
  type << std::endl;

}

Dog::Dog( Dog const & other ) : Animal(other.m_type) {

  std::cout << "Dog copy constructor called." << std::endl;

}

Dog::~Dog( void ) {

  std::cout << "Dog destructor called." << std::endl;

}

Dog& Dog::operator=( Dog const & other ){

  if (this != &other){
    this->m_type = other.m_type;
  }

  return *this;

}

void Dog::makeSound( void ) const {

  std::cout << "Guau guau!" << std::endl;

}