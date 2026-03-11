#include "Point.hpp"

Point::Point( void ) : _x(Fixed(0)), _y(Fixed(0)) {
  
  // std::cout << "Default point constructor called." << std::endl;

}

Point::Point( float x, float y) : _x(Fixed(x)), _y(Fixed(y)) {

  // std::cout << "Parametrized point constructor called." << std::endl;

}

Point::Point( const Point & other ) : _x(other.getX()), _y(other.getY()) {

  // std::cout << "Copy point constructor called." << std::endl;

}

Point::~Point( void ) {

  // std::cout << "Point destructor called." << std::endl;

}

Point& Point::operator=( Point const & other ) {

  // std::cout << "Copy assignment (point) constructor called." << std::endl;
  if (this != &other){
    // this->_x = other.getX();
    // this->_y = other.getY();
  }

  return *this;
}

const Fixed& Point::getX( void ) const {

  return this->_x;

}

const Fixed& Point::getY( void ) const {

  return this->_y;
  
}

std::ostream& operator<<(std::ostream & o, Point const & point ){

  o << "(" << point.getX() << ", " << point.getY() << ")";
  return o;
}