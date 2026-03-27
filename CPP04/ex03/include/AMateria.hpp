#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <iostream>

class AMateria{

  public:

    AMateria( void );
    AMateria( std::string const & type );
    AMateria( AMateria const & other );
    virtual ~AMateria( void );

    AMateria& operator=( AMateria const & other );

    std::string const & getType( void ) const;

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);

  protected:

    std::string const & m_type;


};

#endif