#include "AAnimal.hpp"

AAnimal::AAnimal( void ) : m_type("Generic animal") {

  std::cout << "AAnimal default constructor called." << std::endl;

}


AAnimal::AAnimal( std::string type ) : m_type(type) {

  std::cout << "AAnimal parametrized constructor called." << std::endl;

}


AAnimal::AAnimal( AAnimal const & other ) : m_type(other.m_type) {

  std::cout << "AAnimal copy constructor called." << std::endl;

}

AAnimal::~AAnimal( void ){

  std::cout << "AAnimal destructor called." << std::endl;

}

AAnimal& AAnimal::operator=( AAnimal const & other ){

  if (this != &other){
    this->m_type = other.m_type;
  }

  return *this;

}

std::string AAnimal::getType( void ) const {

  return this->m_type;
  
}
