#ifndef FIXED_H
#define FIXED_H
#include <iostream>

class Fixed{

  public:

    Fixed( void );
    Fixed(const int raw);
    Fixed(const float n);
    Fixed( Fixed const & other);
    ~Fixed( void );
    
    Fixed& operator=( Fixed const & other );
    
    int getRawBits( void ) const;
    void setRawBits( int const raw );

    int toInt( void ) const;
    float toFloat( void) const;

  private:

    int _rawBits;
    static const int _fractionalBits = 8;

};

std::ostream& operator<<(std::ostream & o, Fixed const & fixed ); 

#endif