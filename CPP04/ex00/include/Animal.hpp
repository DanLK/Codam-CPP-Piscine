#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>

class Animal{

  public:

    Animal( void );
    Animal( std::string type );
    Animal( Animal const & other );
    ~Animal( void );

    Animal& operator=( Animal const & other );

    std::string getType( void );

  protected:

    std::string m_type;

};

#endif