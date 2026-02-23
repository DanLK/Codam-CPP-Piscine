#ifndef HUMANB_H
#define HUMANB_H
#include <iostream>

class HumanB{

  public:

  HumanB( std::string name );
  ~HumanB( void );
  Weapon* getWeapon( void );
  void setWeapon( Weapon& weapon );
  void attack();

  private:

  std::string _name;
  Weapon* _weapon;

};

#endif