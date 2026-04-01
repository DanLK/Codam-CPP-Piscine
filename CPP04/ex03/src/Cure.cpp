#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure") {

  std::cout << "Cure default constructor called." << std::endl;

}


Cure::Cure( Cure const & other ) : AMateria(other.m_type) {

  std::cout << "Cure copy constructor called." << std::endl;

}

Cure::~Cure( void ) {

  std::cout << "Cure destructor called." << std::endl;

}

Cure& Cure::operator=(Cure const & other ) {

  std::cout << "Cure copy assignment operator called." << std::endl;
  if (this != &other){
    this->m_type = other.m_type;
  }

  return *this;
}

AMateria* Cure::clone( void ) const {

  AMateria* clone = new Cure();

  return clone;


}


void Cure::use( ICharacter& target ) {

  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;

}