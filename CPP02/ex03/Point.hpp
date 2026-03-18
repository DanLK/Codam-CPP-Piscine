#ifndef POINT_H
#define POINT_H
#include "Fixed.hpp"
#include <iostream>

class Point{

  public:

    Point( void );
    Point( float x, float y );
    Point( Point const & other );
    ~Point( void );

    Point& operator=( Point const & other );

    const Fixed& getX( void ) const;
    const Fixed& getY( void ) const;

  private:

    Fixed const _x;
    Fixed const _y;

};

std::ostream& operator<<(std::ostream & o, Point const & point );

#endif