#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : m_type("Generic Wrong animal") {

  std::cout << "WrongAnimal default constructor called." << std::endl;

}


WrongAnimal::WrongAnimal( std::string type ) : m_type(type) {

  std::cout << "WrongAnimal parametrized constructor called." << std::endl;

}


WrongAnimal::WrongAnimal( WrongAnimal const & other ) : m_type(other.m_type) {

  std::cout << "WrongAnimal copy constructor called." << std::endl;

}

WrongAnimal::~WrongAnimal( void ){

  std::cout << "WrongAnimal destructor called." << std::endl;

}

WrongAnimal& WrongAnimal::operator=( WrongAnimal const & other ){

  if (this != &other){
    this->m_type = other.m_type;
  }

  return *this;

}

std::string WrongAnimal::getType( void ) const {

  return this->m_type;
  
}

void WrongAnimal::makeSound( void ) const {

  std::cout << "Generic Wrong Animal sound" << std::endl;

}