#include "Fixed.hpp"

Fixed::Fixed( void ): _raw_bits(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed & other): _raw_bits(other._raw_bits) {
  std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed( void ){
  std::cout << "Destructor called" << std::endl;
}

Fixed&  Fixed::operator=( Fixed const & other ) {

  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other)
    this->_raw_bits = other.getRawBits();

  return *this;
}

int Fixed::getRawBits( void ) const {

  std::cout << "getRawBits member function called" << std::endl;
  return this->_raw_bits;

}

void Fixed::setRawBits(int const raw){

  this->_raw_bits = raw;

}