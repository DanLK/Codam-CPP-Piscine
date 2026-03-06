#ifndef FIXED_H
#define FIXED_H
#include <iostream>

class Fixed{

  public:

    Fixed( void );
    Fixed( Fixed const & other);
    ~Fixed( void );
    
    Fixed& operator=( Fixed const & other );
    
    int getRawBits( void ) const;
    void setRawBits( int const raw );

  private:

    int _raw_bits;
    static const int _fractional_bits = 8;

};


#endif