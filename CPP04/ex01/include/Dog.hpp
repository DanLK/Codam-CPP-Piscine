#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

  public:

    Dog( void );
    Dog( std::string type );
    Dog( Dog const & other );
    ~Dog( void );

    Dog& operator=( Dog const & other );

    Brain* getBrain( void ) const;
    void setBrain( Brain* brain );

    void makeSound( void ) const;

  private:

    Brain* m_brain;

};

#endif