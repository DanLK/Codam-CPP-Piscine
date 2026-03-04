#ifndef HARL_H
#define HARL_H
#include <iostream>
#include <string>


class Harl{
  
  public:
  
  typedef void (Harl::*fnptr)();
  void complain( std::string level );

  private:

  static std::string _levels_names[4];
  static fnptr _complaints[4];
  void _debug( void );
  void _info( void );
  void _warning( void );
  void _error( void );

};

#endif