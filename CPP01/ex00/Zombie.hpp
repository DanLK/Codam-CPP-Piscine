#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Zombie{

  public:

  Zombie( std::string name);
  Zombie( void );
  ~Zombie( void );

  void announce( void );
  std::string getName( void );
  void setName( std::string name );

  private:

  std::string _name;
};

#endif