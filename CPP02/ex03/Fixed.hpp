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

    bool operator>( Fixed const & other ) const;
    bool operator<( Fixed const & other ) const;
    bool operator>=( Fixed const & other ) const;
    bool operator<=( Fixed const & other ) const;
    bool operator==( Fixed const & other ) const;
    bool operator!=( Fixed const & other ) const;

    Fixed operator+( Fixed const & other ) const;
    Fixed operator-( Fixed const & other ) const;
    Fixed operator*( Fixed const & other ) const;
    Fixed operator/( Fixed const & other ) const;

    Fixed& operator++( void ); // Pre increment; returns a reference to *this after the increment
    Fixed operator++( int ); // Post increment; returns a copy to the object before the increment; takes a dummy variable to disambiguate
    Fixed& operator--( void );
    Fixed operator--( int );

    static Fixed& min( Fixed & a, Fixed & b );
    static const Fixed& min( Fixed const & a, Fixed const & b );
    static Fixed& max( Fixed & a, Fixed & b );
    static const Fixed& max( Fixed const & a, Fixed const & b );

  private:

    int _rawBits;
    static const int _fractionalBits = 8;

};

std::ostream& operator<<(std::ostream & o, Fixed const & fixed ); 

#endif