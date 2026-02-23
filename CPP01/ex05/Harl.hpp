#ifndef HARL_H
#define HARL_H
#include <iostream>
#include <string>
#include <map>


class Harl{
  
  public:
  
  typedef void (Harl::*fnptr)();
  void complain( std::string level );

  private:

  static std::map<std::string, fnptr> _levels_map;
  void _debug( void );
  void _info( void );
  void _warning( void );
  void _error( void );

};

#endif