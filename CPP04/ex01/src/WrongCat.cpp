#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat") {
  
  std::cout << "WrongCat default constructor called." << std::endl;

}

WrongCat::WrongCat( std::string type ) : WrongAnimal("WrongCat") {

  std::cout << "WrongCat parametrized constructor called with parameter " <<
  type << std::endl;

}

WrongCat::WrongCat( WrongCat const & other ) : WrongAnimal(other.m_type) {

  std::cout << "WrongCat copy constructor called." << std::endl;

}

WrongCat::~WrongCat( void ) {

  std::cout << "WrongCat destructor called." << std::endl;

}

WrongCat& WrongCat::operator=( WrongCat const & other ){

  if (this != &other){
    this->m_type = other.m_type;
  }

  return *this;

}

void WrongCat::makeSound( void ) const {

  std::cout << "Wrong Miauuuuuu!" << std::endl;
  
}