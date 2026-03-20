#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat") {
  
  std::cout << "Cat default constructor called." << std::endl;

}

Cat::Cat( std::string type ) : Animal("Cat") {

  std::cout << "Cat parametrized constructor called with parameter " <<
  type << std::endl;

}

Cat::Cat( Cat const & other ) : Animal(other.m_type) {

  std::cout << "Cat copy constructor called." << std::endl;

}

Cat::~Cat( void ) {

  std::cout << "Cat destructor called." << std::endl;

}

Cat& Cat::operator=( Cat const & other ){

  if (this != &other){
    this->m_type = other.m_type;
  }

  return *this;

}

void Cat::makeSound( void ) const {

  std::cout << "Miauuuuuu!" << std::endl;
  
}