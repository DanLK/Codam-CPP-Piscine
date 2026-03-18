#include "Animal.hpp"

Animal::Animal( void ) : m_type("Generic animal") {

  std::cout << "Animal default constructor called." << std::endl;

}


Animal::Animal( std::string type ) : m_type(type) {

  std::cout << "Animal parametrized constructor called." << std::endl;

}


Animal::Animal( Animal const & other ) : m_type(other.m_type) {

  std::cout << "Animal copy constructor called." << std::endl;

}

Animal::~Animal( void ){

  std::cout << "Animal destructor called." << std::endl;

}

Animal& Animal::operator=( Animal const & other ){

  if (this != &other){
    this->m_type = other.m_type;
  }

  return *this;

}

std::string Animal::getType( void ) {

  return this->m_type;
  
}