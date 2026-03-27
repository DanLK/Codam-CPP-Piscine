#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat") {

  this->m_brain = new Brain();
  std::cout << "Cat default constructor called." << std::endl;

}

Cat::Cat( std::string type ) : Animal("Cat") {

  this->m_brain = new Brain();
  std::cout << "Cat parametrized constructor called with parameter " <<
  type << std::endl;

}

Cat::Cat( Cat const & other ) : Animal(other.m_type) {

  this->m_brain= new Brain();
  for (int i = 0; i < 100; i++)
    this->m_brain->setIdea(other.m_brain->getIdea(i), i);

  std::cout << "Cat copy constructor called." << std::endl;

}

Cat::~Cat( void ) {

  delete this->m_brain;
  std::cout << "Cat destructor called." << std::endl;

}

Cat& Cat::operator=( Cat const & other ){

  if (this != &other){
    this->m_type = other.m_type;
    this->m_brain= new Brain();
    for (int i = 0; i < 100; i++)
      this->m_brain->setIdea(other.m_brain->getIdea(i), i);
  }

  return *this;

}

Brain* Cat::getBrain( void ) const {

  return this->m_brain;
}

void Cat::setBrain( Brain* brain ) {

  for (int i = 0; i < 100; i++){
      this->m_brain->setIdea(brain->getIdea(i), i);
  }

}

void Cat::makeSound( void ) const {

  std::cout << "Miauuuuuu!" << std::endl;
  
}