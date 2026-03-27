#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain {

  public:

    Brain( void );
    Brain( Brain const & other );
    ~Brain( void );

    Brain& operator=( Brain const & other );

    std::string getIdea( int i ) const;
    bool setIdea( std::string idea, int i );

  private:

    std::string m_ideas[100];

};

#endif