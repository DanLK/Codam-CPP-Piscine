#include "Fixed.hpp"

Fixed::Fixed( void ): _rawBits(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int n ) : _rawBits(n << this->_fractionalBits){
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float f ) : _rawBits((f * (1 << this->_fractionalBits))) {
  std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( const Fixed & other): _rawBits(other._rawBits) {
  std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed( void ){
  std::cout << "Destructor called" << std::endl;
}

Fixed&  Fixed::operator=( Fixed const & other ) {

  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other)
    this->_rawBits = other.getRawBits();

  return *this;
}

int Fixed::getRawBits( void ) const {

  // std::cout << "getRawBits member function called" << std::endl;
  return this->_rawBits;

}

void Fixed::setRawBits(int const raw){

  this->_rawBits = raw;

}

int Fixed::toInt( void ) const{
  return this->_rawBits >> this->_fractionalBits;
}

float Fixed::toFloat( void ) const{
  return float(this->_rawBits) / (1 << this->_fractionalBits);
}


std::ostream& operator<<(std::ostream & o, Fixed const & fixed ){

  o << fixed.toFloat();
  return o;
}