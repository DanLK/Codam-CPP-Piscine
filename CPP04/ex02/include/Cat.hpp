#ifndef CAT_HPP
#define CAT_HPP
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {

  public:

    Cat( void );
    Cat( std::string type );
    Cat( Cat const & other );
    ~Cat( void );

    Cat& operator=( Cat const & other );

    Brain* getBrain( void ) const;
    void setBrain( Brain* brain );

    void makeSound( void ) const override;

  private:

    Brain* m_brain;

};

#endif