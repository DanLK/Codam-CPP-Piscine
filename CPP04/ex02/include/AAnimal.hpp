#ifndef AANIMAL_HPP
#define AANIMAL_HPP
#include <iostream>

class AAnimal{

  public:

    std::string getType( void ) const;
    virtual void makeSound( void ) const = 0;
    virtual ~AAnimal( void );
  
  protected:
  
    std::string m_type;
    
    AAnimal( void );
    AAnimal( std::string type );
    AAnimal( AAnimal const & other );
    
    AAnimal& operator=( AAnimal const & other );

};

#endif