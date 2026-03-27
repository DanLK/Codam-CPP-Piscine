#include "AMateria.hpp"

AMateria::AMateria( void ) : m_type("default") {

  std::cout << "AMateria default constructor called." << std::endl;

}

AMateria::AMateria( std::string const & type ) : m_type(type) {

  std::cout << "AMateria parametrized constructor called." << std::endl;

}
    

AMateria::AMateria( AMateria const & other ) : m_type(other.m_type) {

  std::cout << "AMateria copy constructor called." << std::endl;
}


AMateria::~AMateria( void ){

  std::cout << "AMateria destructor called." << std::endl;

}

AMateria& AMateria::operator=( AMateria const & other ) {

  std::cout << "AMateria copy assignment operator called." << std::endl;
  if (this != &other){
    this->m_type = other.m_type;
  }
  return *this;

}

std::string const & getType( void ) const {

  return this->m_type;

}

void AMateria::use(ICharacter& target) {

  
}