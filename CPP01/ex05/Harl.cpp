#include "Harl.hpp"

void Harl::complain( std::string level ){

  for (int i = 0; i < 4; i++){
    if (_levels_names[i] == level){
      fnptr complaint = _complaints[i];
      (this->*complaint)();
      return ;
    }
  }
  std::cout << "Invalid complain level." << std::endl;
}

void Harl::_debug( void ){
  std::cout << "This is some debug message" << std::endl;
}

void Harl::_info( void ){
  std::cout << "This is some info" << std::endl;
}

void Harl::_warning( void ){
  std::cout << "This is some warning" << std::endl;
}

void Harl::_error( void ){
  std::cout << "This is some error" << std::endl;
}

std::string Harl::_levels_names[4] = {"debug", "info", "warning", "error"};
Harl::fnptr Harl::_complaints[4] = {&Harl::_debug, &Harl::_info, &Harl::_warning,
                                    &Harl::_error};