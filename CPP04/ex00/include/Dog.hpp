#ifndef DOG_H
#define DOG_H
#include "Animal.hpp"

class Dog : public Animal {

  public:

    Dog( void );
    Dog( std::string type );
    Dog( Dog const & other );
    ~Dog( void );

    Dog& operator=( Dog const & other );

    void makeSound( void );

};

#endif