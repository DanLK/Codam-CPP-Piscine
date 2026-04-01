#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice") {

  std::cout << "Ice default constructor called." << std::endl;

}


Ice::Ice( Ice const & other ) : AMateria(other.m_type) {

  std::cout << "Ice copy constructor called." << std::endl;

}

Ice::~Ice( void ) {

  std::cout << "Ice destructor called." << std::endl;

}

Ice& Ice::operator=(Ice const & other ) {

  std::cout << "Ice copy assignment operator called." << std::endl;
  if (this != &other){
    this->m_type = other.m_type;
  }

  return *this;
}

AMateria* Ice::clone( void ) const {

  AMateria* clone = new Ice();

  return clone;

}


void Ice::use( ICharacter& target ) {

  std::cout << "*shoots an ice bolt at " << target.getName() << " *" << std::endl;

}