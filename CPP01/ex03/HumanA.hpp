#ifndef HUMANA_H
#define HUMANA_H
#include <iostream>

class HumanA{

  public:

  HumanA( std::string name, Weapon& weapon );
  ~HumanA( void );

  void setWeapon( Weapon& weapon);
  void attack();

  private:

  std::string _name;
  Weapon& _weapon;

};

#endif