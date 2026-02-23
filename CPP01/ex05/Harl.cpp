#include "Harl.hpp"

void Harl::complain( std::string level ){

  if (level != "debug" && level != "info" && level != "warning" &&
    level != "error"){
      std::cout << "[" << level << "] Invalid complain level." << std::endl;
      return ;
  }
  fnptr complaint = _levels_map[level];
  (this->*complaint)();
  
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

std::map<std::string, Harl::fnptr> Harl::_levels_map = {
  {"debug", &Harl::_debug},
  {"info", &Harl::_info},
  {"warning", &Harl::_warning},
  {"error", &Harl::_error}};