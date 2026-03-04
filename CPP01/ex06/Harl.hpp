#ifndef HARL_H
#define HARL_H
#include <iostream>
#include <string>
#include <map>


class Harl{
  
  public:
  
  void complain( std::string level );

  private:

  enum _level{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    INVALID
  };
  _level getLevel( std::string );
  void _debug( void );
  void _info( void );
  void _warning( void );
  void _error( void );

};

#endif