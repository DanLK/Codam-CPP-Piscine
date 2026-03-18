#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( void ): _rawBits(0) {
  // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int n ) : _rawBits(n << this->_fractionalBits) {
  // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float f ) : _rawBits(roundf(f * (1 << this->_fractionalBits))) {
  // std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( const Fixed & other): _rawBits(other._rawBits) {
  // std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed( void ) {
  // std::cout << "Destructor called" << std::endl;
}

Fixed&  Fixed::operator=( Fixed const & other ) {

  // std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other)
    this->_rawBits = other.getRawBits();

  return *this;
}

int Fixed::getRawBits( void ) const {

  // std::cout << "getRawBits member function called" << std::endl;
  return this->_rawBits;

}

void Fixed::setRawBits(int const raw) {

  this->_rawBits = raw;

}

int Fixed::toInt( void ) const {
  return this->_rawBits >> this->_fractionalBits;
}

float Fixed::toFloat( void ) const {
  return float(this->_rawBits) / (1 << this->_fractionalBits);
}

bool Fixed::operator>( Fixed const & other ) const {

  return this->_rawBits > other.getRawBits();

}

bool Fixed::operator<( Fixed const & other ) const {

  return this->_rawBits < other.getRawBits();

}

bool Fixed::operator>=( Fixed const & other ) const {

  return this->_rawBits >= other.getRawBits();

}

bool Fixed::operator<=( Fixed const & other ) const {

  return this->_rawBits <= other.getRawBits();

}

bool Fixed::operator==( Fixed const & other ) const {

  return this->_rawBits == other.getRawBits();

}

bool Fixed::operator!=( Fixed const & other ) const {

  return this->_rawBits != other.getRawBits();

}

Fixed Fixed::operator+( Fixed const & other ) {

  Fixed sum = Fixed();
  sum._rawBits = this->_rawBits + other.getRawBits();

  return sum;

}

Fixed Fixed::operator-( Fixed const & other ) {

  Fixed sub = Fixed();
  sub._rawBits = this->_rawBits - other.getRawBits();

  return sub;

}

Fixed Fixed::operator*( Fixed const & other ) {

  Fixed mul = Fixed();
  mul._rawBits = ((long long)this->_rawBits * other.getRawBits()) >> this->_fractionalBits;

  return mul;

}

Fixed Fixed::operator/( Fixed const & other ) {

  Fixed div = Fixed();
  div._rawBits = ((long long)this->_rawBits << this->_fractionalBits)/ other.getRawBits();

  return div;
}

Fixed& Fixed::operator++( void ) {

  this->_rawBits++;

  return *this;

}

Fixed Fixed::operator++( int ) {

  Fixed increment = *this;
  ++(this->_rawBits);

  return increment;
}

Fixed& Fixed::operator--( void ) {

  this->_rawBits--;
  
  return *this;

}

Fixed Fixed::operator--( int ) {

  Fixed increment = *this;
  --(this->_rawBits);

  return increment;
}

Fixed& Fixed::min( Fixed & a, Fixed & b ) {

  if (a <= b)
    return a;
  return b;
}

const Fixed& Fixed::min( Fixed const & a, Fixed const & b ){

  if (a <= b)
    return a;
  return b;
}

Fixed& Fixed::max( Fixed & a, Fixed & b ) {

  if (a >= b)
    return a;
  return b;
}

const Fixed& Fixed::max( Fixed const & a, Fixed const & b ){

  if (a >= b)
    return a;
  return b;
}

std::ostream& operator<<(std::ostream & o, Fixed const & fixed ){

  o << fixed.toFloat();
  return o;
}